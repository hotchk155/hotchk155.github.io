<!--#include file ="sysex.inc"-->
<%
'response.write request.form
	response.addheader "content-type", "application/octet-stream"
	response.addheader "content-disposition", "attachment; filename=msw.syx"
	
	InitMappings
	ReadForm
	WriteSysex
	
%>


