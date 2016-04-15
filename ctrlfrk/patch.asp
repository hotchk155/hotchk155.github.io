<!--#include file ="sysex.inc"-->
<!--#include file ="render.inc"-->
<head>
<style>
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
<h1>CTRLFRK SysEx Builder</h1>
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
<img width=600 src="ctrlfrkcase.gif">
</center>
<hr>
<form name="sysex_file" action="patch.asp?file=true" enctype="multipart/form-data" method="post">
<p>You can load an existing CtrlFrk sysex into this form, or create a new one from scratch <input type="file" name="file" value="File">
<input type="submit" value="Load SysEx Into Form"></p>
</form>
<form name="sysex" action="get_sysex.asp" method="post">
<%
' ================================================================================================
' GLOBALS
' ================================================================================================
%>
<hr>
<p><b>Globals</b></p>
<table>
<tr>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Default Channel</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Default Trigger</td>
</tr>
<%
	Set o = dictMappings.item(1)
	Response.Write "<tr><td>"
	Response.Write "</td><td>"
	RenderChannel o, False
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderGateDuration o, False
	Response.Write "</td><tr>"
%>
</table>
<%
' ================================================================================================
' NOTE INPUTS
' ================================================================================================
%>
<hr>
<p><b>Note Inputs</b></p>
<table>
<tr>
<td></td>
<td>Enable</td>
<td>Input from</td>
<td>Note Priority</td>
<td>Min.Note</td>
<td>Max.Note</td>
<td>Min Vel.</td>
<td>Pitch Bend</td>
</tr>
<%
for count = 1 to 4
	Set o = dictMappings.item(10 + count)
	Response.Write "<tr><td>"
	Response.Write "Input." & count
	Response.Write "</td><td>"
	RenderInputSource o
	Response.Write "</td><td>"
	RenderChannel o, True
	Response.Write "</td><td>"
	RenderPriority o
	Response.Write "</td><td>"
	RenderMinNote o
	Response.Write "</td><td>"
	RenderMaxNote o
	Response.Write "</td><td>"
	RenderMinVel o
	Response.Write "</td><td>"
	RenderBendRange o
	Response.Write "</td></tr>"	
next	
%>
<script language="javascript">
var o_form = document.forms[1];
function XAble_Input(id) {
	var d = (document.getElementById("in" + id + ".src").value != "1");
	document.getElementById("in" + id + ".chan").disabled = d;
	document.getElementById("in" + id + ".prty").disabled = d;
	document.getElementById("in" + id + ".min_note").disabled = d;
	document.getElementById("in" + id + ".max_note").disabled = d;
	document.getElementById("in" + id + ".min_vel").disabled = d;
	document.getElementById("in" + id + ".bend").disabled = d;
}
<% For count = 1 to 4 %>
document.getElementById("in<%=count%>.src").onchange=function(){XAble_Input(<%=count%>);}
XAble_Input(<%=count%>);
<% Next %>	
</script>

</table>

<%
' ================================================================================================
' CV OUTPUTS
' ================================================================================================
%>
<hr>
<p><b>CV outputs</b></p>
<table>
<tr>
<td></td>
<td>CV Source</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Note input</td>
<td>Transpose</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Chan</td>
<td>CC#</td>
</tr>
<%
for count = 1 to 4
	Set o = dictMappings.item(20 + count)
	Response.Write "<tr><td>"
	Response.Write "CV." & Chr(64+count)
	Response.Write "</td><td>"
	RenderCVSource o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderCVEvent o
	Response.Write "</td><td>"
	RenderTranspose o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderChannel o, True
	Response.Write "</td><td>"
	RenderCC o
	Response.Write "</td></tr>"
next	
%>
<script language="javascript">
var o_form = document.forms[1];
function XAble_CVOutput(id) {
	var val = (document.getElementById("cv" + id + ".src").value);
	var d_ev = !(val == "11" || val == "12" || val == "13" || val == "14");
	var d_cc = !(val == "2");
	document.getElementById("cv" + id + ".event").disabled = d_ev;
	document.getElementById("cv" + id + ".trans").disabled = d_ev;
	document.getElementById("cv" + id + ".chan").disabled = d_cc;
	document.getElementById("cv" + id + ".cc").disabled = d_cc;
}
<% For count = 1 to 4 %>
document.getElementById("cv<%=count%>.src").onchange=function(){XAble_CVOutput(<%=count%>);}
XAble_CVOutput(<%=count%>);
<% Next %>	
</script>

</table>

<%
' ================================================================================================
' CV OUTPUTS
' ================================================================================================
%>
<hr>
<p><b>Gate Outputs</b></p>
<table>
<tr>
<td></td>
<td>Source</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Note input event</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Chan</td>
<td>Min.Note</td>
<td>Max.Note</td>
<td>Min Vel.</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>CC#</td>
<td>Switch@</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Ck.Rate</td>
<td>Tk.Ofs</td>
<td>&nbsp;&nbsp;&nbsp;</td>
<td>Trig</td>
</tr>
<%
for count = 1 to 12
	Set o = dictMappings.item(30 + count)
	Response.Write "<tr><td>"
	Response.Write "Gate." & count
	Response.Write "</td><td>"
	RenderGateSource o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderGateEvent o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderChannel o, True
	Response.Write "</td><td>"
	RenderMinNote o
	Response.Write "</td><td>"
	RenderMaxNote o
	Response.Write "</td><td>"
	RenderMinVel o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderCC o
	Response.Write "</td><td>"
	RenderThreshold o
	Response.Write "</td><td>"
	Response.Write "</td><td>"		
	RenderClockDivider o
	Response.Write "</td><td>"
	RenderClockOffset o
	Response.Write "</td><td>"
	Response.Write "</td><td>"
	RenderGateDuration o, True
	Response.Write "</td></tr>"
next	
%>
</table>
<script language="javascript">
var o_form = document.forms[1];
function XAble_GateOutput(id) {
	var val = (document.getElementById("gt" + id + ".src").value);	
	var e_any = (val != "0");
	var e_ev = (val == "11" || val == "12" || val == "13" || val == "14");
	var e_note = (val == "1");
	var e_cc = (val == "2");
	var e_clk = (val == "20"||val == "21");
	document.getElementById("gt" + id + ".event").disabled = !e_ev;
	document.getElementById("gt" + id + ".chan").disabled =  !(e_cc||e_note);
	document.getElementById("gt" + id + ".min_note").disabled = !e_note;
	document.getElementById("gt" + id + ".max_note").disabled = !e_note;
	document.getElementById("gt" + id + ".min_vel").disabled = !e_note;
	document.getElementById("gt" + id + ".cc").disabled = !e_cc;
	document.getElementById("gt" + id + ".thrs").disabled = !e_cc;
	document.getElementById("gt" + id + ".div").disabled = !e_clk;
	document.getElementById("gt" + id + ".ofs").disabled = !e_clk;
	document.getElementById("gt" + id + ".dur").disabled = !e_any;
}
<% For count = 1 to 12 %>
document.getElementById("gt<%=count%>.src").onchange=function(){XAble_GateOutput(<%=count%>);}
XAble_GateOutput(<%=count%>);
<% Next %>	
</script>


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">

</td></tr></table>

</form>



</body>