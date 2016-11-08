<%

Function RenderChannelMapping(o, count)
	Response.Write "<select name=""" & o.Key & ".ch" & count & """ id=""" & o.Key & ".ch" & count & """>"		
	Response.Write "<option "
	If o.ChannelMappings(count-1) = 0 Then response.Write " selected"
	Response.Write " value=""0"">(allow)</option>"
	Response.Write "<option "
	If o.ChannelMappings(count-1) = 1 Then response.Write " selected"
	Response.Write " value=""1"">BLOCK</option>"
	For i = 0 to 15
		Response.Write "<option value=""" & (64+i) & """"
		If o.ChannelMappings(count-1) = 64+i Then response.Write " selected"
		Response.Write ">-&gt;" & (i+1) & "</option>"
	Next
	Response.Write "</select>"		
End Function

Function RenderFilter(o, value, tag)
	Response.Write "<select name=""" & o.Key & "." & tag & """ id=""" & o.Key & "." & tag & """>"		
	Response.Write "<option "
	If value = 0 Then response.Write " selected"
	Response.Write " value=""0"">(allow)</option>"
	Response.Write "<option "
	If value = 1 Then response.Write " selected"
	Response.Write " value=""1"">BLOCK</option>"
	Response.Write "</select>"		
End Function

%>