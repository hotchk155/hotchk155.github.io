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
<h1>Orange Squeeze SysEx Builder</h1>
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
<img width=600 src="img/squeeze.png"> 
</center>
<hr>
<form name="sysex_file" action="patch.asp?file=true" enctype="multipart/form-data" method="post">
<p>You can load an existing sysex patch into this form, or create a new one from scratch <input type="file" name="file" value="File">
<input type="submit" value="Load SysEx Into Form"></p>
</form>
<form name="sysex" action="get_sysex.asp" method="post">
<%
' ================================================================================================
' Channel Filter
' ================================================================================================
%>
<hr>
<p><b>Channel Filter</b></p>
<table>
<tr>
<td></td>
<td>Aux A</td>
<td>Aux B</td>
<td>Aux C</td>
<td>Main</td>
</tr>
<%
Set Port1 = dictMappings.item(2)
Set Port2 = dictMappings.item(3)
Set Port3 = dictMappings.item(4)
Set Port4 = dictMappings.item(1)
for count = 1 to 16
	Response.Write "<tr><td>"
	Response.Write "Ch." & count 
	Response.Write "</td><td>"	
	RenderChannelMapping Port1, count
	Response.Write "</td><td>"	
	RenderChannelMapping Port2, count
	Response.Write "</td><td>"	
	RenderChannelMapping Port3, count
	Response.Write "</td><td>"	
	RenderChannelMapping Port4, count
	Response.Write "</td></tr>"	
next	
%>
</table>

<%
' ================================================================================================
' Message Filter
' ================================================================================================
%>
<hr>
<p><b>Message Filter</b></p>
<table>

<tr>
<td></td>
<td>Aux A</td>
<td>Aux B</td>
<td>Aux C</td>
<td>Main</td>
</td>

<tr>
<td>Note on/off</td>
<td><% RenderFilter Port1, Port1.NoteFilter, "fnote" %></td>
<td><% RenderFilter Port2, Port2.NoteFilter, "fnote" %></td>
<td><% RenderFilter Port3, Port3.NoteFilter, "fnote" %></td>
<td><% RenderFilter Port4, Port4.NoteFilter, "fnote" %></td>
</tr>

<tr>
<td>Bend</td>
<td><% RenderFilter Port1, Port1.BendFilter, "fbend" %></td>
<td><% RenderFilter Port2, Port2.BendFilter, "fbend" %></td>
<td><% RenderFilter Port3, Port3.BendFilter, "fbend" %></td>
<td><% RenderFilter Port4, Port4.BendFilter, "fbend" %></td>
</tr>

<tr>
<td>CC</td>
<td><% RenderFilter Port1, Port1.CCFilter, "fcc" %></td>
<td><% RenderFilter Port2, Port2.CCFilter, "fcc" %></td>
<td><% RenderFilter Port3, Port3.CCFilter, "fcc" %></td>
<td><% RenderFilter Port4, Port4.CCFilter, "fcc" %></td>
</tr>

<tr>
<td>Channel Aftertouch</td>
<td><% RenderFilter Port1, Port1.ChanTouchFilter, "fchantouch" %></td>
<td><% RenderFilter Port2, Port2.ChanTouchFilter, "fchantouch" %></td>
<td><% RenderFilter Port3, Port3.ChanTouchFilter, "fchantouch" %></td>
<td><% RenderFilter Port4, Port4.ChanTouchFilter, "fchantouch" %></td>
</tr>

<tr>
<td>Poly Aftertouch</td>
<td><% RenderFilter Port1, Port1.PolyTouchFilter, "fpolytouch" %></td>
<td><% RenderFilter Port2, Port2.PolyTouchFilter, "fpolytouch" %></td>
<td><% RenderFilter Port3, Port3.PolyTouchFilter, "fpolytouch" %></td>
<td><% RenderFilter Port4, Port4.PolyTouchFilter, "fpolytouch" %></td>
</tr>

<tr>
<td>ProgChange</td>
<td><% RenderFilter Port1, Port1.ProgChangeFilter, "fprogch" %></td>
<td><% RenderFilter Port2, Port2.ProgChangeFilter, "fprogch" %></td>
<td><% RenderFilter Port3, Port3.ProgChangeFilter, "fprogch" %></td>
<td><% RenderFilter Port4, Port4.ProgChangeFilter, "fprogch" %></td>
</tr>

<tr>
<td>ChanPressure</td>
<td><% RenderFilter Port1, Port1.ChanPressureFilter, "fchpres" %></td>
<td><% RenderFilter Port2, Port2.ChanPressureFilter, "fchpres" %></td>
<td><% RenderFilter Port3, Port3.ChanPressureFilter, "fchpres" %></td>
<td><% RenderFilter Port4, Port4.ChanPressureFilter, "fchpres" %></td>
</tr>

<tr>
<td>Sysex</td>
<td><% RenderFilter Port1, Port1.SysexFilter, "fsysex" %></td>
<td><% RenderFilter Port2, Port2.SysexFilter, "fsysex" %></td>
<td><% RenderFilter Port3, Port3.SysexFilter, "fsysex" %></td>
<td><% RenderFilter Port4, Port4.SysexFilter, "fsysex" %></td>
</tr>


<tr>
<td>Clock</td>
<td><% RenderFilter Port1, Port1.ClockFilter, "fclock" %></td>
<td><% RenderFilter Port2, Port2.ClockFilter, "fclock" %></td>
<td><% RenderFilter Port3, Port3.ClockFilter, "fclock" %></td>
<td><% RenderFilter Port4, Port4.ClockFilter, "fclock" %></td>
</tr>

<tr>
<td>Transport</td>
<td><% RenderFilter Port1, Port1.TransportFilter, "ftrans" %></td>
<td><% RenderFilter Port2, Port2.TransportFilter, "ftrans" %></td>
<td><% RenderFilter Port3, Port3.TransportFilter, "ftrans" %></td>
<td><% RenderFilter Port4, Port4.TransportFilter, "ftrans" %></td>
</tr>

<tr>
<td>OtherSysCommon</td>
<td><% RenderFilter Port1, Port1.OtherSysCommonFilter, "fsyscommon" %></td>
<td><% RenderFilter Port2, Port2.OtherSysCommonFilter, "fsyscommon" %></td>
<td><% RenderFilter Port3, Port3.OtherSysCommonFilter, "fsyscommon" %></td>
<td><% RenderFilter Port4, Port4.OtherSysCommonFilter, "fsyscommon" %></td>
</tr>

<tr>
<td>OtherRealtime</td>
<td><% RenderFilter Port1, Port1.OtherRealtimeFilter, "frealtime" %></td>
<td><% RenderFilter Port2, Port2.OtherRealtimeFilter, "frealtime" %></td>
<td><% RenderFilter Port3, Port3.OtherRealtimeFilter, "frealtime" %></td>
<td><% RenderFilter Port4, Port4.OtherRealtimeFilter, "frealtime" %></td>
</tr>

</table>


<hr>
<input type="submit" value="I WANT YOUR SYSEX!">

</td></tr></table>

</form>



</body>