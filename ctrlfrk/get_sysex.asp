<!--#include file ="sysex.inc"-->
<%
	response.addheader "content-type", "application/octet-stream"
	response.addheader "content-disposition", "attachment; filename=ctrlfrk.syx"
	
	InitMappings
	ReadForm
	WriteSysex
	
%>


