# Windows-API-Template
This is a simple game hacking template using the Windows API

## Methods information and usages

<table>
<thead>
<tr>
<th>Method</th>
<th>Description</th>
<th>Example</th>
<th>Signature</th>
</tr>
</thead>
<tbody>
<tr>
<td>FindGameProcess</td>
<td nowrap="">Finds the game process by its name.</td>
<td>HANDLE handle = FindGameProcess("GameName");</td>
<td>HANDLE FindGameProcess(const std::string &amp;gameName);</td>
</tr>
<tr>
<td>FindGameWindow</td>
<td nowrap="">Finds the game window by its name.</td>
<td>HWND gameWindow = FindGameWindow("GameWindowName");</td>
<td>HWND FindGameWindow(const std::string &amp;windowName);</td>
</tr>
<tr>
<td>ReadAddress</td>
<td nowrap="">Reads the value at the address.</td>
<td>Int value = ReadAddress&lt;int&gt;(0x12345678);</td>
<td>T ReadAddress(DWORD address);</td>
</tr>
<tr>
<td>WriteAddress</td>
<td nowrap="">Writes the value at the address.</td>
<td>Bool result = WriteAddress&lt;int&gt;(0x12345678, 100);</td>
<td>Bool WriteAddress(DWORD address, const T &amp;value);</td>
</tr>
<tr>
<td>ReadAddressOffset</td>
<td nowrap="">Reads the value at the address with the offset.</td>
<td>Int value = ReadAddressOffset&lt;int&gt;(0x12345678, 0x10);</td>
<td>T ReadAddressOffset(DWORD address, const DWORD offset);</td>
</tr>
<tr>
<td>WriteAddressOffset</td>
<td nowrap="">Writes the value at the address with the offset.</td>
<td>Bool result = WriteAddressOffset&lt;int&gt;(0x12345678, 0x10, 100);</td>
<td>Bool WriteAddressOffset(DWORD address, DWORD offset, const T &amp;value);</td>
</tr>
<tr>
<td>ReadAddressOffsets</td>
<td nowrap="">Reads the value at the address with the offsets.</td>
<td>Int value = ReadAddressOffsets&lt;int&gt;(0x12345678, {0x10, 0x20});</td>
<td>T ReadAddressOffsets(DWORD address, const std::vector &amp;offsets);</td>
</tr>
<tr>
<td>WriteAddressOffsets</td>
<td nowrap="">Writes the value at the address with the offsets.</td>
<td>Bool result = WriteAddressOffsets&lt;int&gt;(0x12345678, {0x10, 0x20}, 100);</td>
<td>Bool WriteAddressOffsets(DWORD address, const std::vector &amp;offsets, const T &amp;value);</td>
</tr>
<tr>
<td>ReadPointer</td>
<td nowrap="">Reads the value at the address.</td>
<td>Int value = ReadPointer&lt;int&gt;(0x12345678);</td>
<td>T ReadPointer(DWORD address);</td>
</tr>
<tr>
<td>WritePointer</td>
<td nowrap="">Writes the value at the address with the pointer offset.</td>
<td>Bool result = WritePointer&lt;int&gt;(0x12345678, 0x10, 100);</td>
<td>Bool WritePointer(DWORD address, DWORD pointerOffset, const T &amp;value);</td>
</tr>
<tr>
<td>ReadPointerOffset</td>
<td nowrap="">Reads the value at the address with the pointer offset.</td>
<td>Int value = ReadPointerOffset&lt;int&gt;(0x12345678, 0x10);</td>
<td>T ReadPointerOffset(DWORD address, const DWORD offset);</td>
</tr>
<tr>
<td>WritePointerOffset</td>
<td nowrap="">Writes the value at the address with the pointer and offset.</td>
<td>Bool result = WritePointerOffset&lt;int&gt;(0x12345678, 0x10, 0x20, 100);</td>
<td>Bool WritePointerOffset(DWORD address, DWORD pointerOffset, DWORD offset, const T &amp;value);</td>
</tr>
<tr>
<td>ReadPointerOffsets</td>
<td nowrap="">Reads the value at the address with the pointer offsets.</td>
<td>Int value = ReadPointerOffsets&lt;int&gt;(0x12345678, {0x10, 0x20});</td>
<td>T ReadPointerOffsets(DWORD address, const std::vector &amp;offsets);</td>
</tr>
<tr>
<td>WritePointerOffsets</td>
<td nowrap="">Writes the value at the address with the pointer and offsets.</td>
<td>Bool result = WritePointerOffsets&lt;int&gt;(0x12345678, 0x10, {0x20, 0x30}, 100);</td>
<td>Bool WritePointerOffsets(DWORD address, DWORD pointerOffset, const std::vector &amp;offsets, const T &amp;value);</td>
</tr>
<tr>
<td>ReadString</td>
<td nowrap="">Reads the string at the address with the size.</td>
<td>Std::string value = ReadString(0x12345678, 20);</td>
<td>Std::string ReadString(DWORD address, size_t size);</td>
</tr>
<tr>
<td>WriteString</td>
<td nowrap="">Writes the string at the address.</td>
<td>Bool result = WriteString(0x12345678, "Hello World");</td>
<td>Bool WriteString(DWORD address, const std::string &amp;str);</td>
</tr>
<tr>
<td>HotKeysDown</td>
<td nowrap="">Checks if all the keys are pressed.</td>
<td>Bool isPressed = HotKeysDown({VK_A, VK_B, VK_C});</td>
<td>Bool HotKeysDown(const std::vector &amp;keys);</td>
</tr>
<tr>
<td>IsKeyPressed</td>
<td nowrap="">Checks if the key is pressed.</td>
<td>Bool isPressed = IsKeyPressed(VK_A);</td>
<td>Bool IsKeyPressed(int keycode);</td>
</tr>
<tr>
<td>IsKeyToggled</td>
<td nowrap="">Checks if the key is toggled.</td>
<td>Bool isToggled = IsKeyToggled(VK_CAPITAL);</td>
<td>Bool IsKeyToggled(int keycode);</td>
</tr>
<tr>
<td>GetGameName</td>
<td nowrap="">Returns the name of the game.</td>
<td>Std::string gameName = GetGameName();</td>
<td>Std::string GetGameName();</td>
</tr>
<tr>
<td>GetProcessId</td>
<td nowrap="">Returns the process id of the game.</td>
<td>DWORD processId = GetProcessId();</td>
<td>DWORD GetProcessId();</td>
</tr>
<tr>
<td>GetGameHandle4mHWND</td>
<td nowrap="">Returns the game handle from the window handle.</td>
<td>HANDLE gameHandle = GetGameHandle4mHWND(gameWindow);</td>
<td>HANDLE GetGameHandle4mHWND(HWND hwnd);</td>
</tr>
<tr>
<td>GetProcessID4mHWND</td>
<td nowrap="">Returns the process id from the window handle.</td>
<td>DWORD processId = GetProcessID4mHWND(gameWindow);</td>
<td>DWORD GetProcessID4mHWND(HWND hwnd);</td>
</tr>
<tr>
<td>GetGameHandle</td>
<td nowrap="">Returns the game handle.</td>
<td>HANDLE gameHandle = GetGameHandle();</td>
<td>HANDLE GetGameHandle();</td>
</tr>
<tr>
<td>GetGameBaseAddress</td>
<td nowrap="">Returns the base address of the game.</td>
<td>DWORD baseAddress = GetGameBaseAddress();</td>
<td>DWORD GetGameBaseAddress();</td>
</tr>
<tr>
<td>EnableLogs</td>
<td nowrap="">Enables or disables the logs.</td>
<td>EnableLogs(true);</td>
<td>Void EnableLogs(bool status);</td>
</tr>
<tr>
<td>ReadCheatTable</td>
<td nowrap="">Reads the cheat table file and returns the cheat table.</td>
<td>CheatTable ct = ReadCheatTable("cheatTableFile.ct");</td>
<td>CheatTable ReadCheatTable(const std::string &amp;cheatTableFile, int entries = -1);</td>
</tr>
<tr>
<td>AddCheatTableEntry</td>
<td nowrap="">Adds the cheat entry to the cheat table.</td>
<td>AddCheatTableEntry("Armor", CheatTypes.Integer, 0x07290BC8, {}, {VK_CONTROL, 'M'}, CheatActions.SetValue, "150");</td>
<td>Void AddCheatTableEntry(const std::string &amp;description, const std::string &amp;dataType, const DWORD address, const std::vector &amp;offsets, const std::vector &amp;hotkeys, const std::string &amp;hotkeyAction, const std::string hotkeyValue);</td>
</tr>
<tr>
<td>DisplayCheatTable</td>
<td nowrap="">Displays the cheat table.</td>
<td>DisplayCheatTable();</td>
<td>Void DisplayCheatTable(bool showMenuIndex = true, bool showMenuDescription = true, bool showMenuAction = false, bool showMenuHotkeys = true, bool showMenuValue = false);</td>
</tr>
<tr>
<td>ReadCheatTableEntries</td>
<td nowrap="">Reads the cheat table entries and print their values.</td>
<td>ReadCheatTableEntries();</td>
<td>Void ReadCheatTableEntries();</td>
</tr>
<tr>
<td>ActivateCheatTableEntries</td>
<td nowrap="">Activates the cheat table entries.</td>
<td>ActivateCheatTableEntries({1, 2, 3});</td>
<td>Void ActivateCheatTableEntries(const std::vector &amp;cheatEntryIndex);</td>
</tr>
<tr>
<td>ExecuteCheatTable</td>
<td nowrap="">Executes the cheat table and generate trainer.</td>
<td>ExecuteCheatTable(true, VK_ESCAPE, true, true, false, true);</td>
<td>Void ExecuteCheatTable(bool showTrainerOutput = false, int exitTrainerKey = EXIT_TRAINER_KEY, bool showMenuIndex = true, bool showMenuDescription = true, bool showMenuAction = false, bool showMenuHotkeys = true);</td>
</tr>
</tbody>
</table>
