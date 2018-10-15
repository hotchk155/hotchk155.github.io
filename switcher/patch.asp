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

<hr>
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
' SWITCHES
' ================================================================================================
%>
<hr>
<p><b>Switcher outputs</b></p>
<table>
<tr>
<td></td>
<td>Trigger</td>
<td>Chan</td>
<td>Note</td>
<td>Min.Vel</td>
<td>Max.Vel</td>
<td>CC</td>
<td>Min.Val</td>
<td>Max.Val</td>
<td>Duration</td>
<td>Sustain</td>
<td>Hold.Mod</td>
<td>CC</td>
<td>Duty.Mod</td>
<td>CC</td>
</tr>
<%
for count = 1 to 8
	Set o = dictMappings.item(count)
	Response.Write "<tr><td>"
	Response.Write "Port." & Chr(64+count)
	Response.Write "</td><td>"
	RenderTrigType o
	Response.Write "</td><td>"
	RenderTrigChan o
	Response.Write "</td><td>"
	RenderTrigNote o
	Response.Write "</td><td>"
	RenderTrigNoteMinVel o
	Response.Write "</td><td>"
	RenderTrigNoteMaxVel o
	Response.Write "</td><td>"
	RenderTrigCC o
	Response.Write "</td><td>"
	RenderTrigCCMinValue o
	Response.Write "</td><td>"
	RenderTrigCCMaxValue o
	Response.Write "</td><td>"
	RenderEnvHoldTime o
	Response.Write "</td><td>"
	RenderEnvSustain o
	Response.Write "</td><td>"
	RenderDurModType o
	Response.Write "</td><td>"
	RenderDurModCC o
	Response.Write "</td><td>"
	RenderPwmModType o
	Response.Write "</td><td>"
	RenderPwmModCC o
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
<td>Chan</td>
<td>PGM#</td>
<td>Output&nbsp;Ports</td>
</tr>
<%
for count = 1 to 16
	Set o = dictMappings.item(10 + count)
	Response.Write "<tr><td>"
	Response.Write "Slot." & count
	Response.Write "</td><td>"
	RenderPgmChan o
	Response.Write "</td><td>"
	RenderPgmNo o
	Response.Write "</td><td>"
	RenderOutputs o
	Response.Write "</td></tr>"	
next	
%>
</table>


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">


</td></tr></table>

</form>



</body>