<!--#include file ="sysex.inc"-->
<%
'response.write request.form
	response.addheader "content-type", "application/octet-stream"
	response.addheader "content-disposition", "attachment; filename=ctrlfrk.syx"
	
	InitMappings
	ReadForm
	WriteSysex
	
%>


