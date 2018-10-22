<%
'====================================================================
Function RenderSelection(tag, value, dict)
	Dim i, arrKeys, arrItems
	response.Write "<select name=""" & tag & """ id=""" & tag & """>"
	arrKeys = dict.Keys
	arrItems = dict.Items
	For i = 0 to dict.Count - 1
		response.Write "<option value=""" & arrKeys(i) & """"
		if CStr(value) = CStr(arrKeys(i)) then Response.write " selected"
		response.Write ">" & arrItems(i) & "</option>"
	next
	Response.Write "</select>"
End Function
'====================================================================
Function RenderCheckbox(tag, value)
	Response.Write "<input type=checkbox"
	If value Then Response.Write " checked"
	Response.Write " name=""" & tag & """ id=""" & tag & """>"		
End Function 
' =================================================================
Function RenderTrigType(tag, value)
	Dim dict
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(none)"
	dict.add "1", "Note"
	dict.add "2", "CC"
	dict.add "3", "PGM"
	dict.add "4", "Always"
	RenderSelection tag, value, dict
end function	
' =================================================================
Function RenderChan(tag, value, includeDefault)
	Dim i
	Response.Write "<select name=""" & tag & """ id=""" & tag & """>"		
	If includeDefault Then
		Response.Write "<option value=""0"">(default)</option>"
	End If
	For i = 1 to 16
		Response.Write "<option value=""" & i & """"
		If value = i Then Response.Write " selected"
		Response.Write ">" & i & "</option>"
	Next
	Response.Write "</select>"	
End Function 
'====================================================================
Function RenderNote(tag, value)
	Dim i, strNote
	response.Write "<select name=""" & tag & """ id=""" & tag & """>"
	For i = 0 to 127	
		strNote = mid(" CC# DD# E FF# GG# AA# B", 1 + 2 * (i mod 12), 2)
		strNote = trim(strNote & (int(i/12)-2))	
	
		response.Write "<option value=""" & i & """"
		if value = i then Response.write " selected"
		response.Write ">" & i & " " & strNote &  "</option>"	
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderCC(tag, value)
	Dim i
	response.Write "<select name=""" & tag & """ id=""" & tag & """>"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if value = i then Response.write " selected"		
		Select Case i
			'Case 1 
			'	response.Write ">Mod Wheel</option>"
			Case Else
				response.Write ">" & i & "</option>"
		End Select
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderValue(tag, value)
	Dim i
	response.Write "<select name=""" & tag & """ id=""" & tag & """>"
	For i = 0 to 127	
		response.Write "<option value=""" & i & """"
		if value = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderEnvType(tag, value)
	Dim dict
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "Sustain"
	dict.add "1", "Hold"
	dict.add "2", "Hold->Sus"
	dict.add "3", "Sus->Hold"
	dict.add "4", "Release"
	dict.add "5", "Sus->Rel"
	RenderSelection tag, value, dict
end function
'====================================================================
Function RenderEnvHoldTime(tag, value)
	Dim dict, i
	Set dict = Server.CreateObject("Scripting.Dictionary")
	for i = 10 to 90 step 10 
		dict.add CStr(i), CStr(i) & "ms"
	next
	for i = 100 to 900 step 100 
		dict.add CStr(i), CStr(i) & "ms"
	next
	for i = 1 to 16 
		dict.add CStr(i * 1000), CStr(i) & "s"
	next
	RenderSelection tag, value, dict
end function
'====================================================================
Function RenderModDest(tag, value)
	Dim dict
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(none)"
	dict.add "1", "Time"
	dict.add "2", "Duty"
	RenderSelection tag, value, dict
End Function
'====================================================================
Function RenderPgm(tag, value)
	Dim i
	response.Write "<select name=""" & tag & """ id=""" & tag & """>"
	Response.Write "<option value=""-1"">(none)</option>"
	For i = 0 to 127	
		response.Write "<option value=""" & i & """"
		if value = i then Response.write " selected"
		response.Write ">" & (i+1) & "</option>"
	next
	Response.Write "</select>"
end function
%>