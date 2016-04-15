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


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">

</td></tr></table>

</form>



</body>