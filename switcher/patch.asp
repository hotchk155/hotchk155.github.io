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
<h1>MIDI SWITCHER SysEx Builder</h1>
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
<!-- <img width=600 src="img/cvocd.gif"> -->
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
<p><b>Defaults</b></p>

<table>
<%
	Dim o, i, count	
	Set o = dictMappings.item(PARAMH_PORT_DEFAULT)

	response.write "<tr><td>Default MIDI channel for note and CC triggers</td><td>"
	RenderChan o.Key & TrigChanTag, o.TrigChan, false
	response.write "</td>"
	response.write "<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>"	
	response.write "<td>MIDI channel for program changes</td><td>"
	RenderChan o.Key & PgmChanTag, o.PgmChan, false
	response.write "</td></tr>"

%>
</table>
<br>
<table>
<tr>
<td></td>
<td>Envelope</td>
<td>Time</td>
<td>Vel.Mod</td>
<td>CC.Mod</td>
<td>CC.Chan</td>
<td>CC#</td>
<td>&gamma;.cor</td>
</tr>
<%	
	Response.Write "<tr><td>"
	Response.Write "Defaults for modulation settings"
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
<td>Trigger</td>
<td>Channel</td>
<td>Note(Vel)</td>
<td>CC#</td>
<td>Min.Val</td>
<td>Max.Val</td>
<td>...</td>
<td>Envelope</td>
<td>Time</td>
<td>Vel.Mod</td>
<td>CC.Mod</td>
<td>CC.Chan</td>
<td>CC#</td>
<td>&gamma;.cor</td>
</tr>
<%
for count = 1 to 8
	Set o = dictMappings.item(count)
	Response.Write "<tr><td>"
	Response.Write "Port." & Chr(64+count)
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
var o_form = document.forms[1];
function XAble_SwitchOutput(id) {
	var trig = (document.getElementById("out" + id + ".trig").value);
	var dur_mod = (document.getElementById("out" + id + ".dmod").value);
	var pwm_mod = (document.getElementById("out" + id + ".pmod").value);
		
	var e_any_trig = (trig != "0");
	var e_note_trig = (trig == "1");
	var e_cc_trig = (trig == "2");
	var e_cc_dmod = (dur_mod == "102");
	var e_cc_pmod = (pwm_mod == "112");
		
	document.getElementById("out" + id + ".t_ch").disabled = !(e_note_trig || e_cc_trig || e_cc_dmod || e_cc_pmod);
	document.getElementById("out" + id + ".t_note").disabled = !e_note_trig;
	document.getElementById("out" + id + ".t_minvel").disabled =!e_note_trig;
	document.getElementById("out" + id + ".t_maxvel").disabled = !e_note_trig;
	document.getElementById("out" + id + ".t_cc").disabled = !e_cc_trig;
	document.getElementById("out" + id + ".t_minvalue").disabled = !e_cc_trig;
	document.getElementById("out" + id + ".t_maxvalue").disabled = !e_cc_trig;
	document.getElementById("out" + id + ".e_hold").disabled = !(e_note_trig || e_cc_trig);
	document.getElementById("out" + id + ".e_sustain").disabled = !(e_note_trig || e_cc_trig);
	document.getElementById("out" + id + ".dmod").disabled = !e_any_trig
	document.getElementById("out" + id + ".dm_cc").disabled = !(e_any_trig && e_cc_dmod);
	document.getElementById("out" + id + ".pmod").disabled = !e_any_trig
	document.getElementById("out" + id + ".pm_cc").disabled = !(e_any_trig && e_cc_pmod);
}
<% For count = 1 to 8 %>
document.getElementById("out<%=count%>.trig").onchange=function(){XAble_SwitchOutput(<%=count%>);}
document.getElementById("out<%=count%>.dmod").onchange=function(){XAble_SwitchOutput(<%=count%>);}
document.getElementById("out<%=count%>.pmod").onchange=function(){XAble_SwitchOutput(<%=count%>);}
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
<td>PGM#</td>
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
<td>PGM#</td>
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
dim slot
for count = 1 to 8

	slot = count
	Set o = dictMappings.item(10+slot)
	Response.Write "<tr><td>"
	Response.Write "Slot." & slot
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
	Response.Write "</td><td>"
	
	Response.Write "</td><td>"

	slot = 8 + count
	Set o = dictMappings.item(10+slot)
	Response.Write "Slot." & slot
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
</table>


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">


</td></tr></table>

</form>



</body>