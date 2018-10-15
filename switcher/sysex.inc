<%

// Sysex ID
Const MANUF_ID_0	= &H00
Const MANUF_ID_1	= &H7f
Const MANUF_ID_2	= &H19 // MIDI switcher patch

	
Const PARAMH_PORTA = 1
Const PARAMH_PORTB = 2
Const PARAMH_PORTC = 3
Const PARAMH_PORTD = 4
Const PARAMH_PORTE = 5
Const PARAMH_PORTF = 6
Const PARAMH_PORTG = 7
Const PARAMH_PORTH = 8

Const PARAML_TRIG_NONE = 0
Const PARAML_TRIG_NOTE = 1
Const PARAML_TRIG_CC = 2
Const PARAML_TRIG_PGM = 3

Const PARAML_TRIG2_VELOCITY	= 4
Const PARAML_TRIG2_VALUE = 5

Const PARAML_ENV_SUSTAIN = 50
Const PARAML_ENV_HOLD = 51

Const PARAML_DUR_MOD_NONE	= 100
Const PARAML_DUR_MOD_VELOCITY = 101
Const PARAML_DUR_MOD_CC	= 102

Const PARAML_PWM_MOD_NONE = 110
Const PARAML_PWM_MOD_VELOCITY =111
Const PARAML_PWM_MOD_CC	= 112

Const PARAMH_PGM_ALL 	= 10
Const PARAMH_PGM_SLOT1 	= 11
Const PARAMH_PGM_SLOT2 	= 12
Const PARAMH_PGM_SLOT3 	= 13
Const PARAMH_PGM_SLOT4 	= 14
Const PARAMH_PGM_SLOT5 	= 15
Const PARAMH_PGM_SLOT6 	= 16
Const PARAMH_PGM_SLOT7 	= 17
Const PARAMH_PGM_SLOT8 	= 18
Const PARAMH_PGM_SLOT9 	= 19
Const PARAMH_PGM_SLOT10	= 20
Const PARAMH_PGM_SLOT11	= 21
Const PARAMH_PGM_SLOT12	= 22
Const PARAMH_PGM_SLOT13 = 23
Const PARAMH_PGM_SLOT14 = 24
Const PARAMH_PGM_SLOT15 = 25
Const PARAMH_PGM_SLOT16 = 26

Const PARAML_PGM_CLEAR	= 0
Const PARAML_PGM_MATCH	= 1
Const PARAML_PGM_PORT	= 2

	
Dim dictMappings

' =================================================================
Function WriteParam(a,b,c,d)
'	Response.Write a & ", " & b & ", " & c & ", " & d & "<br>"
	Response.BinaryWrite ChrB(a) & ChrB(b) & ChrB(c) & ChrB(d) 
End Function

' =================================================================
' SWITCH OUTPUT
' =================================================================
Class SwitchOutput

	Public Key
	Public TrigType 
	Public TrigChan 
	Public TrigNote 
	Public TrigNoteMinVel 
	Public TrigNoteMaxVel 
	Public TrigCC 
	Public TrigCCMinValue 
	Public TrigCCMaxValue
	Public EnvSustain
	Public EnvHoldTime
	Public DurModType 
	Public DurModCC 
	Public PwmModType 
	Public PwmModCC 
	
	'--------------------------
	Public Sub Class_Initialize
		Key = ""	
		TrigType = PARAML_TRIG_NONE
		TrigChan = 1
		TrigNote = 36 
		TrigNoteMinVel = 0
		TrigNoteMaxVel = 127
		TrigCC = 1
		TrigCCMinValue = 64
		TrigCCMaxValue = 127
		EnvSustain = 0
		EnvHoldTime = 100
		DurModType = PARAML_MOD_NONE
		DurModCC = 1
		PwmModType = PARAML_MOD_NONE
		PwmModCC = 1
	End Sub
	'--------------------------	
	Public Sub ReadForm
		Me.TrigType = CByte(Request.Form(Me.Key & ".trig"))
		Me.TrigChan = CByte(Request.Form(Me.Key & ".t_ch"))
		Me.TrigNote = CByte(Request.Form(Me.Key & ".t_note"))
		Me.TrigNoteMinVel = CByte(Request.Form(Me.Key & ".t_minvel"))
		Me.TrigNoteMaxVel = CByte(Request.Form(Me.Key & ".t_maxvel"))
		Me.TrigCC = CByte(Request.Form(Me.Key & ".t_cc"))
		Me.TrigCCMinValue = CByte(Request.Form(Me.Key & ".t_minvalue"))
		Me.TrigCCMaxValue = CByte(Request.Form(Me.Key & ".t_maxvalue"))
		Me.EnvSustain= CByte(Request.Form(Me.Key & ".e_sustain"))
		Me.EnvHoldTime = CByte(Request.Form(Me.Key & ".e_hold"))
		Me.DurModType = CByte(Request.Form(Me.Key & ".dmod"))
		Me.DurModCC = CByte(Request.Form(Me.Key & ".dm_cc"))
		Me.PwmModType = CByte(Request.Form(Me.Key & ".pmod"))
		Me.PwmModCC = CByte(Request.Form(Me.Key & ".pm_cc"))
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
	
		Select Case Me.TrigType
			Case PARAML_TRIG_NONE, PARAML_TRIG_PGM
				WriteParam id, Me.TrigType, 0, 0
			Case PARAML_TRIG_NOTE
				WriteParam id, PARAML_TRIG_NOTE, Me.TrigChan, Me.TrigNote
				WriteParam id, PARAML_TRIG2_VELOCITY, Me.TrigNoteMaxVel, Me.TrigNoteMinVel
				If Me.DurModType = PARAML_DUR_MOD_CC Then 
					WriteParam id, Me.DurModType, Me.TrigChan, Me.DurModCC
				Else 
					WriteParam id,Me.DurModType, 0, 0
				End If 
				If Me.PwmModType = PARAML_PWM_MOD_CC Then 
					WriteParam id, Me.PwmModType, Me.TrigChan, Me.PwmModCC
				Else 
					WriteParam id,Me.PwmModType, 0, 0
				End If 
			Case PARAML_TRIG_CC
				WriteParam id, PARAML_TRIG_CC, Me.TrigChan, Me.TrigCC
				WriteParam id, PARAML_TRIG2_VALUE, Me.TrigCCMaxValue, Me.TrigCCMinValue
				If Me.DurModType = PARAML_DUR_MOD_CC Then 
					WriteParam id, Me.DurModType, Me.TrigChan, Me.DurModCC
				Else 
					WriteParam id,Me.DurModType, 0, 0
				End If 
				If Me.PwmModType = PARAML_PWM_MOD_CC Then 
					WriteParam id, Me.PwmModType, Me.TrigChan, Me.PwmModCC
				Else 
					WriteParam id,Me.PwmModType, 0, 0
				End If 
		End Select
		If Me.TrigType <> PARAML_TRIG_NONE Then 
			WriteParam id, PARAML_ENV_SUSTAIN, 0, Me.EnvSustain 
			WriteParam id, PARAML_ENV_HOLD, CInt(Me.EnvHoldTime/128), Me.EnvHoldTime Mod 128
		End If
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2		
			Case PARAML_TRIG_NONE, PARAML_TRIG_PGM
				Me.TrigType = p2
			Case PARAML_TRIG_NOTE
				Me.TrigType = p2
				Me.TrigChan = v1
				Me.TrigNote = v2				
			Case PARAML_TRIG_CC
				Me.TrigType = p2
				Me.TrigChan = v1
				Me.TrigCC = v2				
			Case PARAML_TRIG2_VELOCITY
				Me.TrigNoteMinVel = v2
				Me.TrigNoteMaxVel = v1
			Case PARAML_TRIG2_VALUE
				Me.TrigCCMinValue = v2
				Me.TrigCCMaxValue = v1
			Case PARAML_ENV_SUSTAIN 
				Me.EnvSustain = v2
			Case PARAML_ENV_HOLD = 51
				Me.EnvHoldTime = 128 * v1 + v2
			Case PARAML_MOD_NONE, PARAML_MOD_VELOCITY
				Me.ModType = p2
			Case PARAML_DUR_MOD_CC
				Me.DurModType = p2
				Me.DurModCC = v2	'always on the trigger channel
			Case PARAML_PWM_MOD_CC
				Me.PwmModType = p2
				Me.PwmModCC = v2	'always on the trigger channel
		end select
	End Sub
End Class

' =================================================================
' PROGRAM CHANGE
' =================================================================
Class ProgramChange

	Public Key
	Public Chan
	Public PGM 
	Public Out1
	Public Out2
	Public Out3
	Public Out4
	Public Out5
	Public Out6
	Public Out7
	Public Out8

	
	'--------------------------
	Public Sub Class_Initialize
		Key = ""	
		Chan = 0
		PGM = 0
		Out1 = 0
		Out2 = 0
		Out3 = 0
		Out4 = 0
		Out5 = 0
		Out6 = 0
		Out7 = 0
		Out8 = 0 
	End Sub
	'--------------------------	
	Public Sub ReadForm
		Me.Chan = CByte(Request.Form(Me.Key & ".chan"))
		Me.PGM = CByte(Request.Form(Me.Key & ".pgm"))
		Me.Out1 = CByte(Request.Form(Me.Key & ".out1")= "on")
		Me.Out2 = CByte(Request.Form(Me.Key & ".out2")= "on")
		Me.Out3 = CByte(Request.Form(Me.Key & ".out3")= "on")
		Me.Out4 = CByte(Request.Form(Me.Key & ".out4")= "on")
		Me.Out5 = CByte(Request.Form(Me.Key & ".out5")= "on")
		Me.Out6 = CByte(Request.Form(Me.Key & ".out6")= "on")
		Me.Out7= CByte(Request.Form(Me.Key & ".out7")= "on")
		Me.Out8 = CByte(Request.Form(Me.Key & ".out8")= "on")
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
		if Me.Chan <> 0 Then
			WriteParam id, PARAML_PGM_MATCH, Me.Chan, Me.PGM
			WriteParam id, PARAML_PGM_PORT, 1, Me.Out1
			WriteParam id, PARAML_PGM_PORT, 2, Me.Out2
			WriteParam id, PARAML_PGM_PORT, 3, Me.Out3
			WriteParam id, PARAML_PGM_PORT, 4, Me.Out4
			WriteParam id, PARAML_PGM_PORT, 5, Me.Out5
			WriteParam id, PARAML_PGM_PORT, 6, Me.Out6
			WriteParam id, PARAML_PGM_PORT, 7, Me.Out7
			WriteParam id, PARAML_PGM_PORT, 8, Me.Out8
		Else
			WriteParam id, PARAML_PGM_CLEAR, 0, 1 'clear
		End If
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2		
			Case PARAML_PGM_MATCH
				Me.Chan = v1
				Me.PGM = v2
			Case PARAML_TRIG_PORT
				Select Case v1
					Case 1
						Me.Out1 = v2
					Case 2
						Me.Out2 = v2
					Case 3
						Me.Out3 = v2
					Case 4
						Me.Out4 = v2
					Case 5
						Me.Out5 = v2
					Case 6
						Me.Out6 = v2
					Case 7
						Me.Out7 = v2
					Case 8
						Me.Out8 = v2
				End Select
		end select
	End Sub
End Class

Function InitMappings
	Set dictMappings = Server.CreateObject("Scripting.Dictionary")
	For i = 1 to 8
		Set o = New SwitchOutput
		o.Key = "out" & i
		dictMappings.Add i, o
	Next

	For i = 1 to 16
		Set o = New ProgramChange
		o.Key = "pc" & i
		dictMappings.Add 10+i, o
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
    if (midb(data,index,4) <> (ChrB(&HF0) & ChrB(MANUF_ID_0) & ChrB(MANUF_ID_1) & ChrB(&H12))) and _   
		(midb(data,index,4) <> (ChrB(&HF0) & ChrB(MANUF_ID_0) & ChrB(MANUF_ID_1) & ChrB(MANUF_ID_2))) then
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