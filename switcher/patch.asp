<!--#include file ="sysex.inc"-->
<!--#include file ="render.inc"-->
<head>
<style>
body {
    font-family: arial;
}

table {
    font-family: arial;
    font-size: 12px;
    margin-top: 0px;
    margin-bottom: 0px;
    margin-right: 0px;
    margin-left: 0px;
    padding: 0px;
	line-height: 1;
}
</style>
</head>
<body>
<h1>MIDI SWITCHER/RELAY SWITCHER SysEx Builder</h1>
<%
	InitMappings
	
	If Request.QueryString("file") <> "" Then
		If Not ReadSysex Then
%><b style="color:red">ERROR IN SYSEX FILE - NOT LOADED!!</b><%		
		End If
	End If
%>

<table width=800><tr><td>
<center>
<img width=600 src="img/switcher.png"> 
</center>
<hr>
<form name="sysex_file" action="patch.asp?file=true" enctype="multipart/form-data" method="post">
<table>
<tr><td>You can load an existing sysex into this form, or create a new one from scratch<br>
</td>
<td>:</td>
<td><input type="file" name="file" value="File"></td>
<td><input type="submit" value="Load SysEx Into Form"></td>
<tr>
</table>
</form>
<form name="sysex" action="get_sysex.asp" method="post">
<%
' ================================================================================================
' DEFAULT
' ================================================================================================
%>
<hr>
<p><b>Default Values For This Patch</b></p>
<%
	Dim o, i, count	
	Set o = dictMappings.item(PARAMH_PORT_DEFAULT)
%>	
<table>
<tr>
<td title="The default MIDI channel where we listen for note and CC messages that will trigger the switch">Trig.Chan</td>
<td title="The MIDI channel where we listen for program change messages">PGM.Chan</td>
<td title="The default envelope shape for switching">Envelope</td>
<td title="The default switching duration">Time</td>
<td title="The default selection for how note velocity modulates switching">Vel.Mod</td>
<td title="The default selection for how a separate CC can modulate switching">CC.Mod</td>
<td title="The default selection for the MIDI channel where we listen for CC messages that modulate switching">CC.Chan</td>
<td title="The default selection for the CC number that modulates switching">CC#</td>
<td title="The default selection for whether gamma correction will apply to switching">&gamma;.cor</td>
</tr>
<%	
	Response.Write "<tr><td>"
	RenderChan o.Key & TrigChanTag, o.TrigChan, false 	
	Response.Write "</td><td>"
	RenderChan o.Key & PgmChanTag, o.PgmChan, false		
	Response.Write "</td><td>"
	RenderEnvType o.Key & EnvTypeTag, o.EnvType
	Response.Write "</td><td>"
	RenderEnvHoldTime o.Key & EnvHoldTimeTag, o.EnvHoldTime
	Response.Write "</td><td>"
	RenderModDest o.Key & ModVelDestTag, o.ModVelDest
	Response.Write "</td><td>"
	RenderModDest o.Key & ModCCDestTag, o.ModCCDest
	Response.Write "</td><td>"
	RenderChan o.Key & ModCCChanTag, o.ModCCChan, true
	Response.Write "</td><td>"
	RenderCC o.Key & ModCCTag, o.ModCC
	Response.Write "</td><td>"
	RenderCheckBox o.Key & GammaTag, o.Gamma
	Response.Write "</td></tr>"	
%>
</table>
<script language="javascript">
function XAble_Default() {
	var id = <%=PARAMH_PORT_DEFAULT%>;
	var e_modcc = (document.getElementById("def<%=ModCCDestTag%>").value) != "0";

	document.getElementById("def<%=ModCCChanTag%>").disabled = !e_modcc;
	document.getElementById("def<%=ModCCTag%>").disabled =  !e_modcc;
}
document.getElementById("def<%=ModCCDestTag%>").onchange=function(){XAble_Default(<%=count%>);}
XAble_Default();
</script>
<%
' ================================================================================================
' SWITCHES
' ================================================================================================
%>
<hr>
<p><b>Switcher outputs</b></p>
<table>
<tr>
<td></td>
<td title="The type of MIDI messages that triggers switching on this channel&#13;Can be a MIDI note ON message, a CC value within a range or we can &#13;select that the channel is switched by program change messages">Trigger</td>
<td title="The MIDI channel where we listen for note and CC messages to trigger switching">Channel</td>
<td title="In Note mode, the specific MIDI note that will trigger this channel">Note(Vel)</td>
<td title="In CC mode, this is the specific controller number that triggers the channel">CC#</td>
<td title="In note mode these fields select the range of note velocities that can&#13;trigger the channel. In CC mode this is a range of controller values &#13;that will trigger the channel">Min.Val</td>
<td>Max.Val</td>
<td title="Check the box to override the default pulse-shaping for this channel">...</td>
<td title="Select the 'shape' of the pulse using this setting:&#13;'Sustain' means that the switch stays on as long as the trigger is present&#13;'Hold' means that the switch stays on for the specified time period&#13;These can be combined to give a minimum switch time or to extend the trigger time&#13;'Release' means that the switch power 'fades away' during Hold time and is most useful with LEDs or light bulbs">Envelope</td>
<td title="The duration of the 'Hold' or 'Release' period">Time</td>
<td title="Whether the note velocity scales, or 'modulates', the Hold time or PWM duty (power)">Vel.Mod</td>
<td title="Whether a specified MIDI controller scales, or 'modulates', the Hold time or PWM duty (power)">CC.Mod</td>
<td title="The MIDI channel where we listen for the CC for modulation">CC.Chan</td>
<td title="The CC number controlling modulation">CC#</td>
<td title="Whether we apply 'gamma correction' to the PWM duty (switch power)&#13;When used with LEDs or light bulbs, this gives them a better range of perceived brightness">&gamma;.cor</td>
</tr>
<%
for count = 1 to 8
	Set o = dictMappings.item(count)
	Response.Write "<tr><td>"
	Response.Write Chr(64+count)
	Response.Write "</td><td>"
	RenderTrigType o.Key & TrigTypeTag, o.TrigType
	Response.Write "</td><td>"
	RenderChan o.Key & TrigChanTag, o.TrigChan, true
	Response.Write "</td><td>"
	RenderNote o.Key & TrigNoteTag, o.TrigNote
	Response.Write "</td><td>"
	RenderCC o.Key & TrigCCTag, o.TrigCC
	Response.Write "</td><td>"
	RenderValue o.Key & TrigMinValueTag, o.TrigMinValue
	Response.Write "</td><td>"
	RenderValue o.Key & TrigMaxValueTag, o.TrigMaxValue
	Response.Write "</td><td>"
	RenderCheckbox o.Key & ChangeDefaultTag, o.ChangeDefault
	Response.Write "</td><td>"
	RenderEnvType o.Key & EnvTypeTag, o.EnvType
	Response.Write "</td><td>"
	RenderEnvHoldTime o.Key & EnvHoldTimeTag, o.EnvHoldTime
	Response.Write "</td><td>"
	RenderModDest o.Key & ModVelDestTag, o.ModVelDest
	Response.Write "</td><td>"
	RenderModDest o.Key & ModCCDestTag, o.ModCCDest
	Response.Write "</td><td>"
	RenderChan o.Key & ModCCChanTag, o.ModCCChan, true
	Response.Write "</td><td>"
	RenderCC o.Key & ModCCTag, o.ModCC
	Response.Write "</td><td>"
	RenderCheckBox o.Key & GammaTag, o.Gamma
	Response.Write "</td></tr>"	
next	
%>
</table>
<script language="javascript">
function XAble_SwitchOutput(id) {
	var trig = (document.getElementById("out" + id + "<%=TrigTypeTag%>").value);		
	var e_any_trig = (trig != "0");
	var e_note_trig = (trig == "1");
	var e_cc_trig = (trig == "2");
	var e_ovr = e_any_trig && document.getElementById("out" + id + "<%=ChangeDefaultTag%>").checked;
	var e_modcc = (document.getElementById("out" + id + "<%=ModCCDestTag%>").value) != "0";

	document.getElementById("out" + id + "<%=TrigChanTag%>").disabled = !(e_note_trig || e_cc_trig);
	document.getElementById("out" + id + "<%=TrigNoteTag%>").disabled = !e_note_trig;
	document.getElementById("out" + id + "<%=TrigCCTag%>").disabled = !e_cc_trig;
	document.getElementById("out" + id + "<%=TrigMaxValueTag%>").disabled = !(e_note_trig || e_cc_trig);
	document.getElementById("out" + id + "<%=TrigMinValueTag%>").disabled = !(e_note_trig || e_cc_trig);
	document.getElementById("out" + id + "<%=ChangeDefaultTag%>").disabled = !e_any_trig;
	document.getElementById("out" + id + "<%=EnvTypeTag%>").disabled = !e_ovr;
	document.getElementById("out" + id + "<%=EnvHoldTimeTag%>").disabled = !e_ovr;
	document.getElementById("out" + id + "<%=ModVelDestTag%>").disabled = !e_ovr;
	document.getElementById("out" + id + "<%=ModCCDestTag%>").disabled = !e_ovr;
	document.getElementById("out" + id + "<%=ModCCChanTag%>").disabled = !(e_ovr && e_modcc);
	document.getElementById("out" + id + "<%=ModCCTag%>").disabled =  !(e_ovr && e_modcc);
	document.getElementById("out" + id + "<%=GammaTag%>").disabled = !e_ovr;	
}
<% For count = 1 to 8 %>
document.getElementById("out<%=count%><%=TrigTypeTag%>").onchange=function(){XAble_SwitchOutput(<%=count%>);}
document.getElementById("out<%=count%><%=ChangeDefaultTag%>").onchange=function(){XAble_SwitchOutput(<%=count%>);}
document.getElementById("out<%=count%><%=ModCCDestTag%>").onchange=function(){XAble_SwitchOutput(<%=count%>);}
XAble_SwitchOutput(<%=count%>);
<% Next %>	
</script>
<%
' ================================================================================================
' PROGRAM
' ================================================================================================
%>
<hr>
<p><b>Program Changes</b></p>
<table>
<tr>
<td></td>
<td title="The MIDI program number that will activate this 'slot' and trigger selected channels">PGM#</td>
<td>A</td>
<td>B</td>
<td>C</td>
<td>D</td>
<td>E</td>
<td>F</td>
<td>G</td>
<td>H</td>
<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
<td></td>
<td title="The MIDI program number that will activate this 'slot' and trigger selected channels">PGM#</td>
<td>A</td>
<td>B</td>
<td>C</td>
<td>D</td>
<td>E</td>
<td>F</td>
<td>G</td>
<td>H</td>

</tr>
<%
for count = 0 to 7

	Set o = dictMappings.item(10+count)
	Response.Write "<tr><td>"
	If count = 0 Then 
		Response.Write "INIT"
		Response.Write "</td><td>"

	Else
		Response.Write "Slot." & (count)
		Response.Write "</td><td>"
		RenderPgm o.Key & PgmTag, o.Pgm
	End If 
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out1Tag, o.Out1
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out2Tag, o.Out2
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out3Tag, o.Out3
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out4Tag, o.Out4
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out5Tag, o.Out5
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out6Tag, o.Out6
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out7Tag, o.Out7
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out8Tag, o.Out8
	Response.Write "</td><td>"
	
	Response.Write "</td><td>"

	Set o = dictMappings.item(18+count)
	Response.Write "Slot." & (count+8)
	Response.Write "</td><td>"
	RenderPgm o.Key & PgmTag, o.Pgm
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out1Tag, o.Out1
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out2Tag, o.Out2
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out3Tag, o.Out3
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out4Tag, o.Out4
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out5Tag, o.Out5
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out6Tag, o.Out6
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out7Tag, o.Out7
	Response.Write "</td><td>"
	RenderCheckbox o.Key & Out8Tag, o.Out8
	
	Response.Write "</td></tr>"	
next	
%>
<script language="javascript">
function XAble_PGM(id) {
	var pgm = (document.getElementById("pc" + id + "<%=PgmTag%>").value);		
	document.getElementById("pc" + id + "<%=Out1Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out2Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out3Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out4Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out5Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out6Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out7Tag%>").disabled = !pgm;
	document.getElementById("pc" + id + "<%=Out8Tag%>").disabled = !pgm;
}
<% For count = 1 to 16 %>
document.getElementById("pc<%=count%><%=PgmTag%>").onchange=function(){XAble_PGM(<%=count%>);}
XAble_PGM(<%=count%>);
<% Next %>	
</script>
</table>


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">


</td></tr></table>

</form>



</body>