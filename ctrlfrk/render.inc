<%

' =================================================================
Function RenderChannel(o, bIncludeDefault)
	Response.Write "<select name=""" & o.Key & ".chan"">"		
	If bIncludeDefault Then
		Response.Write "<option value=""default"""
		If o.ChanType = 2 Then Response.Write " selected"
		Response.Write ">(default)</option>"
	End If
		
	
	For i = 1 to 16
		Response.Write "<option value=""" & i & """"
		If o.ChanType = 0 And o.ChanNumber = i Then Response.Write " selected"
		Response.Write ">Chan." & i & "</option>"
	Next
		
	Response.Write "<option value=""omni"""
	If o.ChanType = 1 Then Response.Write " selected"
	Response.Write ">(OMNI)</option>"

	Response.Write "</select>"
	
End Function 

'====================================================================
Function RenderMinNote(o)
	response.Write "<select name=""" & o.Key & ".min_note"">"
	For i = 0 to 127	
		response.Write "<option value=""" & i & """"
		if o.MinNote = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function

'====================================================================
Function RenderMaxNote(o)
	response.Write "<select name=""" & o.Key & ".max_note"">"
	For i = 0 to 127	
		response.Write "<option value=""" & i & """"
		if o.MaxNote = i then Response.write " selected"
		if i = 0 then 
			response.Write ">(single)</option>"
		else
			response.Write ">" & i & "</option>"
		end if
	next
	Response.Write "</select>"
end function

'====================================================================
Function RenderMinVel(o)
	response.Write "<select name=""" & o.Key & ".min_vel"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.MinVel = i then Response.write " selected"
		if i = 1 then 
			response.Write ">(any)</option>"
		else
			response.Write ">" & i & "</option>"
		end if
	next
	Response.Write "</select>"
end function

'====================================================================
Function RenderCC(o)
	response.Write "<select name=""" & o.Key & ".cc"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.CC = i then Response.write " selected"
		if i = 1 then 
			response.Write ">Mod Wheel</option>"
		else
			response.Write ">cc#" & i & "</option>"
		end if
	next
	Response.Write "</select>"
end function

'====================================================================
Function RenderThreshold(o)
	response.Write "<select name=""" & o.Key & ".thrs"">"
	For i = 1 to 127	
		response.Write "<option value=""" & i & """"
		if o.Threshold = i then Response.write " selected"
		response.Write ">" & i & "</option>"
	next
	Response.Write "</select>"
end function

'====================================================================
Function RenderSelection(name, default, dict)
	response.Write "<select name=""" & name & """>"
	arrKeys = dict.Keys
	arrItems = dict.Items
	For i = 0 to dict.Count - 1
		response.Write "<option value=""" & arrKeys(i) & """"
		if CStr(default) = CStr(arrKeys(i)) then Response.write " selected"
		response.Write ">" & arrItems(i) & "</option>"
	next
	Response.Write "</select>"
End Function

'====================================================================
Function RenderInputSource(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(disable)"
	dict.add "1", "ENABLE"
	RenderSelection o.Key & ".src", o.Source, dict
end function

'====================================================================
Function RenderPriority(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(Single Note)"
	dict.add "1", "Most recently played"
	dict.add "2", "Lowest pitch"
	dict.add "3", "Lowest pitch (spread)"
	dict.add "4", "Highest pitch"
	dict.add "5", "Highest pitch (spread)"
	dict.add "6", "Oldest note"
	dict.add "7", "Randomised"
	dict.add "8", "All recently played"
	RenderSelection o.Key & ".prty", o.Priority, dict
end function

'====================================================================
Function RenderBendRange(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	For i = 0 to 24
		dict.add CStr(i), "+/-" & i
	next
	RenderSelection o.Key & ".bend", o.BendRange, dict
end function

'====================================================================
Function RenderCVSource(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(disable)"
	dict.add "11", "Note input #1"
	dict.add "12", "Note input #2"
	dict.add "13", "Note input #3"
	dict.add "14", "Note input #4"
	dict.add "2", "MIDI CC"
	dict.add "20", "BPM to CV"
	dict.add "120", "Calibration +1V"
	dict.add "123", "Calibration +4V"
	RenderSelection o.Key & ".src", o.Source, dict
end function

'====================================================================
Function RenderCVEvent(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "1", "1st Priority Note"
	dict.add "2", "2nd Priority Note"
	dict.add "3", "3rd Priority Note"
	dict.add "4", "4th Priority Note"
	dict.add "20", "Velocity to CV"
	dict.add "21", "Pitch Bend to CV"
	RenderSelection o.Key & ".event", o.InputEvent, dict
end function

'====================================================================
Function RenderTranspose(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "100", "+3oct"
	dict.add "88", "+2oct"
	dict.add "76", "+1oct"
	for i=11 to 1 step -1
		dict.add cstr(64+i), cstr(i)
	Next
	dict.add "64", "(none)"
	for i=-1 to -11 step -1
		dict.add cstr(64+i), cstr(i)
	Next
	dict.add "52", "-1oct"
	dict.add "40", "-2oct"
	dict.add "28", "-3oct"
	RenderSelection o.Key & ".trans", o.Transpose, dict
end function

'====================================================================
Function RenderGateSource(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "0", "(disable)"
	dict.add "11", "Note input #1"
	dict.add "12", "Note input #2"
	dict.add "13", "Note input #3"
	dict.add "14", "Note input #4"
	dict.add "1", "MIDI note"
	dict.add "2", "MIDI CC"
	dict.add "20", "Clock Tick"
	dict.add "21", "Clock Tick+Run"
	dict.add "22", "Clock Running"
	dict.add "23", "Clock Start"
	dict.add "24", "Clock Continue"
	dict.add "25", "Clock Stop"
	RenderSelection o.Key & ".src", o.Source, dict
end function

'====================================================================
Function RenderGateEvent(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")
	dict.add "1", "Note 1 gate"
	dict.add "2", "Note 2 gate"
	dict.add "3", "Note 3 gate"
	dict.add "4", "Note 4 gate"
	dict.add "5", "Any note gate"
	dict.add "0", "No notes gate"
	dict.add "11", "Note 1 trigger"
	dict.add "12", "Note 2 trigger"
	dict.add "13", "Note 3 trigger"
	dict.add "14", "Note 4 trigger"
	dict.add "15", "Any note trigger"
	dict.add "10", "No notes trigger"
	RenderSelection o.Key & ".event", o.InputEvent, dict
end function

'====================================================================
Function RenderClockDivider(o)
	Set dict = Server.CreateObject("Scripting.Dictionary")	
	dict.add "3", "1/32"
	dict.add "4", "1/16T"
	dict.add "6", "1/16"
	dict.add "8", "1/8T"
	dict.add "9", "1/16D"
	dict.add "1", "1/8"
	dict.add "16", "1/4T"
	dict.add "18", "1/8D"
	dict.add "24", "1/4"
	dict.add "32", "1/2T"
	dict.add "36", "1/4D"
	dict.add "48", "1/2"
	dict.add "72", "1/2D"
	dict.add "96", "1"
	RenderSelection o.Key & ".div", o.Divider, dict	
end function

'====================================================================
Function RenderClockOffset(o)
	response.Write "<select name=""" & o.Key & ".ofs"">"
	For i = 0 to 127	
		response.Write "<option value=""" & i & """"
		if o.Offset = i then Response.write " selected"
		if i = 0 then 
			response.Write ">(none)</option>"
		else
			response.Write ">+" & i & "</option>"
		end if
	next
	Response.Write "</select>"
End Function

'====================================================================
Function RenderGateDuration(o, bIncludeDefault)
	response.Write "<select name=""" & o.Key & ".dur"">"
	If bIncludeDefault then
		response.Write "<option value=""default"">(default)</option>"
	
		response.Write "<option value=""inf"""
		If o.DurationType = 0 then response.Write " selected"	
		response.Write ">(gate)</option>"
	end if
	
	For i = 5 to 125 step 5
		response.Write "<option value=""" & i & """"
		if o.DurationType = 1 and o.Duration = i then Response.write " selected"
		if i = 0 then 
			response.Write ">(gate)</option>"
		else
			response.Write ">" & i & "ms</option>"
		end if
	next
	Response.Write "</select>"
End Function

%>