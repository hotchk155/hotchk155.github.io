<%
Const MANUF_ID_0 = &H00
Const MANUF_ID_1 = &H7F 
Const MANUF_ID_2 = &H12 		

	
Dim dictMappings

' =================================================================
Function WriteParam(a,b,c,d)
'	Response.Write a & ", " & b & ", " & c & ", " & d & "<br>"
	Response.BinaryWrite ChrB(a) & ChrB(b) & ChrB(c) & ChrB(d) 
End Function

Class PortDef
	Public Key 
	Public ChannelMappings
	Public NoteFilter 
	Public BendFilter 
	Public CCFilter 
	Public ChanTouchFilter
	Public PolyTouchFilter
	Public AftertouchFilter 
	Public ProgChangeFilter 
	Public ChanPressureFilter 
	Public SysexFilter 
	Public ClockFilter 
	Public TransportFilter 
	Public OtherSysCommonFilter 
	Public OtherRealtimeFilter
	'--------------------------
	Public Sub Class_Initialize
		Key = ""	
		ChannelMappings = Array(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)		
		NoteFilter = 0
		BendFilter = 0
		CCFilter = 0
		ChanTouchFilter = 0
		PolyTouchFilter = 0
		ProgChangeFilter = 0
		ChanPressureFilter = 0
		SysexFilter = 0
		ClockFilter = 0
		TransportFilter = 0
		OtherSysCommonFilter = 0
		OtherRealtimeFilter = 0
	End Sub	
	'--------------------------	
	Public Sub ReadForm
		Me.NoteFilter = CByte(Request.Form(Me.Key & ".fnote"))
		Me.BendFilter = CByte(Request.Form(Me.Key & ".fbend"))
		Me.CCFilter = CByte(Request.Form(Me.Key & ".fcc"))
		Me.ChanTouchFilter = CByte(Request.Form(Me.Key & ".fchantouch"))
		Me.PolyTouchFilter = CByte(Request.Form(Me.Key & ".fpolytouch"))
		Me.ProgChangeFilter = CByte(Request.Form(Me.Key & ".fprogch"))
		Me.ChanPressureFilter = CByte(Request.Form(Me.Key & ".fchpres"))
		Me.SysexFilter = CByte(Request.Form(Me.Key & ".fsysex"))
		Me.ClockFilter = CByte(Request.Form(Me.Key & ".fclock"))
		Me.TransportFilter = CByte(Request.Form(Me.Key & ".ftrans"))
		Me.OtherSysCommonFilter = CByte(Request.Form(Me.Key & ".fsyscommon"))
		Me.OtherRealtimeFilter = CByte(Request.Form(Me.Key & ".frealtime"))		
		For i = 0 to 15
			Me.ChannelMappings(i) = CByte(Request.Form(Me.Key & ".ch" & (i+1)))
		Next
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
	
		WriteParam id, 1, 0, Me.NoteFilter 
		WriteParam id, 2, 0, Me.BendFilter 
		WriteParam id, 3, 0, Me.CCFilter 
		WriteParam id, 4, 0, Me.ChanTouchFilter 
		WriteParam id, 5, 0, Me.PolyTouchFilter 
		WriteParam id, 6, 0, Me.ProgChangeFilter 
		WriteParam id, 7, 0, Me.ChanPressureFilter 
		WriteParam id, 8, 0, Me.SysexFilter 
		WriteParam id, 9, 0, Me.ClockFilter 
		WriteParam id, 10, 0, Me.TransportFilter 
		WriteParam id, 11, 0, Me.OtherSysCommonFilter 
		WriteParam id, 12, 0, Me.OtherRealtimeFilter
		For i = 0 to 15
			WriteParam id, 64+i, 0, Me.ChannelMappings(i)
		Next	
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2
			case 1
				Me.NoteFilter = v2
			case 2
				Me.BendFilter = v2
			case 3
				Me.CCFilter = v2
			case 4
				Me.ChanTouchFilter = v2
			case 5
				Me.PolyTouchFilter = v2
			case 6
				Me.ProgChangeFilter = v2
			case 7
				Me.ChanPressureFilter = v2
			case 8
				Me.SysexFilter = v2
			case 9
				Me.ClockFilter = v2
			case 10
				Me.TransportFilter = v2
			case 11
				Me.OtherSysCommonFilter = v2
			case 12
				Me.OtherRealtimeFilter = v2
			case 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79
				Me.ChannelMappings(p2-64) = v2
		End select	
	End Sub
End Class


Function InitMappings
	Set dictMappings = Server.CreateObject("Scripting.Dictionary")
	For i = 1 to 4
		Set o = New PortDef
		o.Key = "p" & i
		If i>1 then
			o.ClockFilter = 1
		end if		
		dictMappings.Add i, o
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