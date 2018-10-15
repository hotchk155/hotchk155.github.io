<%
'====================================================================
Function RenderSelection(name, default, dict)
	response.Write "<select name=""" & name & """ id=""" & name & """>"
	arrKeys = dict.Keys
	arrItems = dict.Items
	For i = 0 to dict.Count - 1
		response.Write "<option value=""" & arrKeys(i) & """"
		if CStr(default) = CStr(arrKeys(i)) then Response.write " selected"
		response.Write ">" & arrItems(i) & "</option>"
	next
	Response.Write "</select>"
End Function

' =================================================================
Function RenderTrigType(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(None)"
	dict.add "1", "Note on"
	dict.add "2", "CC Change"
	dict.add "3", "Program Change"
	RenderSelection o.Key & ".trig", o.TrigType, dict
end function	
' =================================================================
Function RenderTrigChan(o)
	Response.Write "<select name=""" & o.Key & ".t_ch"" id=""" & o.Key & ".t_ch"">"		
	For i = 1 to 16
		Response.Write "<option value=""" & i & """"
		If o.TrigChan = i Then Response.Write " selected"
		Response.Write ">Chan." & i & "</option>"
	Next
	Response.Write "</select>"	
End Function 
'====================================================================
Function RenderTrigNote(o)
	response.Write "<select name=""" & o.Key & ".t_note"" id=""" & o.Key & ".t_note"">"
	For i = 0 to 127	
		strNote = mid(" CC# DD# E FF# GG# AA# B", 1 + 2 * (i mod 12), 2)
		strNote = trim(strNote & (int(i/12)-1))	
	
		response.Write "<option value=""" & i & """"
		if o.TrigNote = i then Response.write " selected"
		response.Write ">" & i & " " & strNote &  "</option>"	
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderTrigNoteMinVel(o)
	response.Write "<select name=""" & o.Key & ".t_minvel"" id=""" & o.Key & ".t_minvel"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.TrigNoteMinVel = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderTrigNoteMaxVel(o)
	response.Write "<select name=""" & o.Key & ".t_maxvel"" id=""" & o.Key & ".t_maxvel"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.TrigNoteMaxVel = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderTrigCC(o)
	response.Write "<select name=""" & o.Key & ".t_cc"" id=""" & o.Key & ".t_cc"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.TrigCC = i then Response.write " selected"		
		Select Case i
			Case 1 
				response.Write ">Mod Wheel</option>"
			Case Else
				response.Write ">cc#" & i & "</option>"
		End Select
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderTrigCCMinValue(o)
	response.Write "<select name=""" & o.Key & ".t_minvalue"" id=""" & o.Key & ".t_minvalue"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.TrigCCMinValue = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderTrigCCMaxValue(o)
	response.Write "<select name=""" & o.Key & ".t_maxvalue"" id=""" & o.Key & ".t_maxvalue"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.TrigCCMaxValue = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderEnvSustain(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "Off"
	dict.add "1", "On"
	RenderSelection o.Key & ".e_sustain", o.EnvSustain, dict
end function
'====================================================================
Function RenderEnvHoldTime(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(none)"
	for i = 10 to 90 step 10 
		dict.add CStr(i), CStr(i) & "ms"
	next
	for i = 100 to 900 step 100 
		dict.add CStr(i), CStr(i) & "ms"
	next
	for i = 1 to 16 
		dict.add CStr(i * 1000), CStr(i) & "s"
	next
	RenderSelection o.Key & ".e_hold", o.EnvHoldTime, dict
end function
' =================================================================
Function RenderDurModType(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "100", "(None)"
	dict.add "101", "Velocity"
	dict.add "102", "CC"
	RenderSelection o.Key & ".dmod", o.DurModType, dict
end function	
'====================================================================
Function RenderDurModCC(o)
	response.Write "<select name=""" & o.Key & ".dm_cc"" id=""" & o.Key & ".dm_cc"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.DurModCC = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
' =================================================================
Function RenderPwmModType(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "110", "(None)"
	dict.add "111", "Velocity"
	dict.add "112", "CC"
	RenderSelection o.Key & ".pmod", o.PwmModType, dict
end function	
'====================================================================
Function RenderPwmModCC(o)
	response.Write "<select name=""" & o.Key & ".pm_cc"" id=""" & o.Key & ".pm_cc"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.PwmModCC = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function

' =================================================================
Function RenderPgmChan(o)
	Response.Write "<select name=""" & o.Key & ".chan"" id=""" & o.Key & ".chan"">"		
	Response.Write "<option value=""0"">(None)</option>"
	For i = 1 to 16
		Response.Write "<option value=""" & i & """"
		If o.Chan = i Then Response.Write " selected"
		Response.Write ">Chan." & i & "</option>"
	Next
	Response.Write "</select>"	
End Function 
'====================================================================
Function RenderPgmNo(o)
	response.Write "<select name=""" & o.Key & ".m_pgm"" id=""" & o.Key & ".m_pgm"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.PGM = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function
'====================================================================
Function RenderOutputs(o)

	response.Write "A<input type=""checkbox"" name=""" & o.Key & ".out1"" id=""" & o.Key & ".out1"""
	If o.Out1 = 1 then response.Write " selected"
	response.Write ">"

	response.Write "&nbsp;B<input type=""checkbox"" name=""" & o.Key & ".out2"" id=""" & o.Key & ".out2"""
	If o.Out2 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;C<input type=""checkbox"" name=""" & o.Key & ".out3"" id=""" & o.Key & ".out3"""
	If o.Out3 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;D<input type=""checkbox"" name=""" & o.Key & ".out4"" id=""" & o.Key & ".out4"""
	If o.Out4 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;E<input type=""checkbox"" name=""" & o.Key & ".out5"" id=""" & o.Key & ".out5"""
	If o.Out5 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;F<input type=""checkbox"" name=""" & o.Key & ".out6"" id=""" & o.Key & ".out6"""
	If o.Out6 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;G<input type=""checkbox"" name=""" & o.Key & ".out7"" id=""" & o.Key & ".out7"""
	If o.Out7 = 1 then response.Write " selected"
	response.Write ">"
	
	response.Write "&nbsp;H<input type=""checkbox"" name=""" & o.Key & ".out8"" id=""" & o.Key & ".out8"""
	If o.Out8 = 1 then response.Write " selected"
	response.Write ">"
	
End Function 	
	
%>