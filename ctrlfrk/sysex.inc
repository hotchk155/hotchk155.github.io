<%


Const MANUF_ID_0 = &H00
Const MANUF_ID_1 = &H7F 
Const MANUF_ID_2 = &H12 		


Dim dictMappings


' =================================================================
Function ReadChan(o)
	If Request.Form(o.Key & ".chan") = "omni" then
		o.ChanType = 1
		o.ChanNumber = 0
	elseif Request.Form(o.Key & ".chan") = "default" then
		o.ChanType = 2
		o.ChanNumber = 0
	else
		o.ChanType = 0
		o.ChanNumber = CLng(Request.Form(o.Key & ".chan"))
	end if
end function 
' =================================================================
Function ReadDuration(o)
	If request.form(o.Key & ".dur") = "inf" then
		o.DurationType = 0
		o.Duration = 0
	elseIf request.form(o.Key & ".dur") = "default" then
		o.DurationType = 2
		o.Duration = 0
	else
		o.DurationType = 1
		o.Duration = CByte(Request.Form(o.Key & ".dur"))
	end if	
End Function 
' =================================================================
Function ReadPriority(o)
	o.Priority = CByte(Request.Form(o.Key & ".prty"))
End Function 
' =================================================================
Function ReadBendRange(o)
	o.BendRange = CByte(Request.Form(o.Key & ".bend"))
End Function 
' =================================================================
Function ReadMinNote(o)
	o.MinNote = CByte(Request.Form(o.Key & ".min_note"))
End Function 
' =================================================================
Function ReadMaxNote(o)
	o.MaxNote = CByte(Request.Form(o.Key & ".max_note"))
End Function 
' =================================================================
Function ReadMinVel(o)
	o.MinVel = CByte(Request.Form(o.Key & ".min_vel"))
End Function 
' =================================================================
Function ReadSource(o)
	o.Source = CByte(Request.Form(o.Key & ".src"))
End Function 
' =================================================================
Function ReadInputEvent(o)
	o.InputEvent = CByte(Request.Form(o.Key & ".event"))
End Function 
' =================================================================
Function ReadTranspose(o)
'response.write (o.Key & ".trans") & ">" & CByte(Request.Form(o.Key & ".trans"))
	o.Transpose = CByte(Request.Form(o.Key & ".trans"))
End Function 
' =================================================================
Function ReadCC(o)
	o.CC = CByte(Request.Form(o.Key & ".cc"))
End Function 
' =================================================================
Function ReadThreshold(o)
	o.Threshold = CByte(Request.Form(o.Key & ".thrs"))
End Function 
' =================================================================
Function ReadDivider(o)
	o.Divider = CByte(Request.Form(o.Key & ".div"))
End Function 
' =================================================================
Function ReadOffset(o)
	o.Offset = CByte(Request.Form(o.Key & ".ofs"))
End Function 
' =================================================================
Function WriteParam(a,b,c,d)
'	Response.Write a & ", " & b & ", " & c & ", " & d & "<br>"
	Response.BinaryWrite ChrB(a) & ChrB(b) & ChrB(c) & ChrB(d) 
End Function


' =================================================================
' Globals
' =================================================================
Class Globals
	Public Key 
	Public ChanType 
	Public ChanNumber
	Public DurationType
	Public Duration
	'--------------------------
	Public Sub Class_Initialize
		Key = ""	
		ChanType = 0 'specific
		ChanNumber = 1
		DurationType = 1 'ms
		Duration = 15
	End Sub
	'--------------------------
	Public Sub ReadForm
		ReadChan Me
		ReadDuration Me
	End Sub	
	'--------------------------
	Public Sub WriteSysex(id)
		WriteParam id, 2, Me.ChanType, Me.ChanNumber
		WriteParam id, 9, Me.DurationType, Me.Duration
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2
			case 2
				Me.ChanType = v1
				Me.ChanNumber = v2
			case 9
				Me.DurationType = v1
				Me.Duration = v2
		end select
	End Sub
End Class

' =================================================================
' NOTE INPUT
' =================================================================
Class NoteInput
	Public Key 
	Public Source 
	Public ChanType 
	Public ChanNumber
	Public Priority 
	Public MinNote 
	Public MaxNote
	Public MinVel 
	Public BendRange
	'--------------------------
	Public Sub Class_Initialize
		Key = ""	
		Source = 0
		ChanType = 2 'default
		ChanNumber = 0	
		Priority = 1
		MinNote = 0
		MaxNote = 127
		MinVel = 0
		BendRange = 3
	End Sub	
	'--------------------------	
	Public Sub ReadForm
		ReadSource Me
		ReadChan Me
		ReadPriority Me
		ReadMinNote Me
		ReadMaxNote Me
		ReadMinVel Me
		ReadBendRange Me
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
		WriteParam id, 1, Me.Source, 0
		WriteParam id, 2, Me.ChanType, Me.ChanNumber
		WriteParam id, 3, 0, Me.MinNote
		WriteParam id, 4, 0, Me.MaxNote
		WriteParam id, 5, 0, Me.MinVel
		WriteParam id, 7, 0, Me.BendRange
		WriteParam id, 8, 0, Me.Priority
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2
			case 1
				Me.Source = v1
			case 2
				Me.ChanType = v1
				Me.ChanNumber = v2
			case 3
				Me.MinNote = v2
			case 4
				Me.MaxNote = v2
			case 5
				Me.MinVel = v2
			case 7
				Me.BendRange = v2
			case 8
				Me.Priority = v2
		end select
	End Sub
End Class

' =================================================================
' CV OUTPUT
' =================================================================
Class CVOutput
	Public Key 
	Public Source 
	Public InputEvent
	Public Transpose
	Public ChanType
	Public ChanNumber
	Public CC
	'--------------------------
	Public Sub Class_Initialize
		Key = ""
		Source = 0
		InputEvent = 0
		Transpose = 64
		ChanType = 2 'default
		ChanNumber = 0	
		CC = 1
	End Sub	
	'--------------------------
	Public Sub ReadForm
		ReadSource Me
		ReadInputEvent Me
		ReadTranspose Me
		ReadChan Me
		ReadCC Me		
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
		Select Case Me.Source
			Case 11,12,13,14
				WriteParam id, 1, Me.Source, Me.InputEvent
			Case 2
				WriteParam id, 1, Me.Source, Me.CC
			case else
				WriteParam id, 1, Me.Source, 0
		End select
		WriteParam id, 2, Me.ChanType, Me.ChanNumber
		WriteParam id, 12, 0, Me.Transpose
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2
			case 1
				select case v1
					case 11,12,13,14
						Me.Source = v1
						Me.InputEvent = v2
					case 2
						Me.Source = v1
						Me.CC = v2
					case else 
						Me.Source = v1
				end select					
			case 2
				Me.ChanType = v1
				Me.ChanNumber = v2
			case 12
				Me.Transpose = v2
		end select
	End Sub
End Class

' =================================================================
' GATE OUTPUT
' =================================================================
Class GateOutput
	Public Key 
	Public Source
	Public InputEvent
	Public ChanType
	Public ChanNumber
	Public MinNote
	Public MaxNote
	Public MinVel
	Public CC
	Public Threshold
	Public Divider
	Public Offset
	Public DurationType
	Public Duration
	'--------------------------
	Public Sub Class_Initialize
		Key  = ""
		Source = 0
		InputEvent = 0
		ChanType = 2 'default
		ChanNumber = 0	
		MinNote = 0
		MaxNote = 127
		MinVel = 0
		CC = 0		
		Threshold = 64
		Divider = 6
		Offset = 0
		DurationType = 2 'default
		Duration = 0
	End Sub
	'--------------------------
	Public Sub ReadForm
		ReadSource Me
		ReadInputEvent Me
		ReadChan Me
		ReadMinNote Me
		ReadMaxNote Me
		ReadMinVel Me
		ReadCC Me
		ReadThreshold Me
		ReadDivider Me
		ReadOffset Me
		ReadDuration Me
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
		Select Case Me.Source
			Case 11,12,13,14
				WriteParam id, 1, Me.Source, Me.InputEvent
			Case 1
				WriteParam id, 1, Me.Source, Me.MinNote
				WriteParam id, 2, Me.ChanType, Me.ChanNumber
				WriteParam id, 4, 0, Me.MaxNote
				WriteParam id, 5, 0, Me.MinVel
			Case 2
				WriteParam id, 1, Me.Source, Me.CC
				WriteParam id, 2, Me.ChanType, Me.ChanNumber
				WriteParam id, 13, 0, Me.Threshold
			Case 20, 21
				WriteParam id, 1, Me.Source, Me.Divider
				WriteParam id, 11, 0, Me.Offset			
			case else
				WriteParam id, 1, Me.Source, 0
		End select
		WriteParam id, 9, Me.DurationType, Me.Duration
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2
			case 1
				select case v1
					case 11,12,13,14
						Me.Source = v1
						Me.InputEvent = v2
					case 1
						Me.Source = v1
						Me.MinNote = v2
					case 2
						Me.Source = v1
						Me.CC = v2
					case 20, 21
						Me.Source = v1
						Me.Divider = v2					
					case else 
						Me.Source = v1
				end select					
			case 2
				Me.ChanType = v1
				Me.ChanNumber = v2
			case 4
				Me.MaxNote = v2
			case 5
				Me.MinVel = v2
			case 9
				Me.DurationType = v1
				Me.Duration = v2
			case 11
				Me.Offset = v2
			case 13
				Me.Threshold = v2
		end select
	End Sub
End Class

Function InitMappings
	Set dictMappings = Server.CreateObject("Scripting.Dictionary")

	Set o = New Globals
	o.Key = "global"
	dictMappings.Add 1, o
	
	' NOTE INPUTS
	For i = 1 to 4
		Set o = New NoteInput
		o.Key = "in" & i
		dictMappings.Add 10 + i, o
	Next

	' CV OUTPUTS
	For i = 1 to 4
		Set o = New CVOutput
		o.Key = "cv" & i
		dictMappings.Add 20 + i, o
	Next

	' GATE OUTPUTS
	For i = 1 to 12
		Set o = New GateOutput
		o.Key = "gt" & i
		dictMappings.Add 30 + i, o
	Next	
End Function

Function ReadForm
	For each o in dictMappings.Items
		o.ReadForm
	Next
End Function

Function WriteSysex
	arrKeys = dictMappings.Keys
	arrItems = dictMappings.Items
	response.binarywrite chrb(&HF0) 
	response.binarywrite chrb(MANUF_ID_0) 
	response.binarywrite chrb(MANUF_ID_1) 
	response.binarywrite chrb(MANUF_ID_2) 		
	For i = 0 to UBound(arrKeys)
		Set o = arrItems(i)
		o.WriteSysex(arrKeys(i))
	Next
	response.binarywrite chrb(&HF7) 
End Function

function ReadSysEx
	Dim data
	ReadSysEx = false
	data = request.BinaryRead(request.TotalBytes)
	
	index = 0
	for i=1 to lenb(data) - 4
		if midb(data,i,4) = (chrb(13) & chrb(10) & chrb(13) & chrb(10)) then
			index = i + 4
			exit for
		end if
	next	
	if index = 0 then
		exit function 
	end if
    if midb(data,index,4) <> (ChrB(&HF0) & ChrB(MANUF_ID_0) & ChrB(MANUF_ID_1) & ChrB(MANUF_ID_2)) then
		exit function 
	end if
	index = index + 4
	
	do while index <= lenb(data) 
		if midb(data,index,1) = chrb(&hF7) then exit do
		if index + 4 >= lenb(data) then exit function
		Set o = dictMappings(ascb(midb(data,index,1)))
		o.ReadSysex _
			ascb(midb(data,index,1)), _
			ascb(midb(data,index+1,1)), _
			ascb(midb(data,index+2,1)), _
			ascb(midb(data,index+3,1))
		index = index + 4		
	loop
	ReadSysEx = true
end function
%>