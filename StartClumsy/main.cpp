#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <thread>
#include <random>

void ThrowError(const char* Error)
{
	const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	printf(Error, "\n");

	std::this_thread::sleep_for(std::chrono::seconds(3));
	TerminateProcess(GetCurrentProcess(), 0);

	return;
}

BOOLEAN Elevated()
{
	BOOL fRet = FALSE;
	HANDLE hToken = NULL;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
	{
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize))
		{
			fRet = Elevation.TokenIsElevated;
		}
	}

	if (hToken)
		CloseHandle(hToken);

	return fRet;
}

BOOLEAN MouseClick()
{
	auto Input = INPUT();
	RtlZeroMemory(&Input, sizeof(Input));

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	SendInput(1, &Input, sizeof(Input));
	RtlZeroMemory(&Input, sizeof(Input));

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(1, &Input, sizeof(Input));
	RtlZeroMemory(&Input, sizeof(Input));

	return TRUE;
}

BOOLEAN SendKBButton(int keycode)
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = keycode;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	return TRUE;
}

BOOLEAN LogKeyPress(const char* key, int color)
{
	const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

	printf("[%s] - Pressed\n", key);

	SetConsoleTextAttribute(hConsole, 15);

	return TRUE;
}

int main()
{
	// Administrator
	if (!Elevated())
	{
		ThrowError("[ERROR] Software needs admin rights to run properly!");
		return -1;
	}

	// Total uses
	int TotalUses = 0;

	// Windows
    auto GameWindow = FindWindowA("grcWindow", "Grand Theft Auto V");
    auto Clumsy = FindWindowA(NULL, "clumsy 0.2");
	
	// First one
	if (!GameWindow == NULL)
	{
		printf("[LOG] Found GTAV window\n");
	}
	else
	{
		ThrowError("[ERROR] Couldn't find GTAV window, aborting...");
		return -1;
	}

	// First one
	if (!Clumsy == NULL)
	{
		printf("[LOG] Found Clumsy window\n\n");
	}
	else
	{
		ThrowError("[ERROR] Couldn't find Clumsy window, aborting...");
		return -1;
	}

	// Message
	printf("F9 - Setup best config | F10 - Enable/Disable | F11 - Kill process | F12 - Get current cursor pos\n\n");

	// No messing up
	SetWindowPos(Clumsy, NULL, 0, 0, 0, 0, SWP_NOSIZE);

	while (TRUE)
	{
		// Validate
		if (Clumsy == NULL)
		{
			ThrowError("[ERROR] Clumsy got closed, aborting...");
			return -1;
		}

		if (GameWindow == NULL)
		{
			ThrowError("[ERROR] GTAV got closed, aborting...");
			return -1;
		}

		if (GetAsyncKeyState(VK_F9))
		{
			// Sleep
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			LogKeyPress("F9", 14);

			SetForegroundWindow(Clumsy);
			SetWindowPos(Clumsy, NULL, 0, 0, 0, 0, SWP_NOSIZE);

			// Drop
			SetCursorPos(40, 195);
			MouseClick();

			// Throttle
			SetCursorPos(40, 222);
			MouseClick();

			// Duplicate
			SetCursorPos(40, 254);
			MouseClick();

			// Out of order
			SetCursorPos(40, 286);
			MouseClick();

			// Tamper
			SetCursorPos(40, 308);
			MouseClick();

			// Count :: Type "50"
			SetCursorPos(280, 250);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x35); // 5
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// Drop :: Type "70"
			SetCursorPos(558, 190);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x37); // 7
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// Throttle :: Type "70"
			SetCursorPos(558, 220);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x37); // 7
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// Duplicate :: Type "70"
			SetCursorPos(558, 250);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x37); // 7
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// Out Of Order :: Type "70"
			SetCursorPos(558, 280);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x37); // 7
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// Tamper :: Type "70"
			SetCursorPos(558, 310);
			MouseClick();

			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x08); // Backspace
			SendKBButton(0x37); // 7
			SendKBButton(0x30); // 0

			std::this_thread::sleep_for(std::chrono::milliseconds(5));

			// All receiving packets
			SetCursorPos(558, 100);
			MouseClick();

			SetCursorPos(572, 177);
			MouseClick();

			SetCursorPos(399, 162);
			MouseClick();
		}

		if (GetAsyncKeyState(VK_F10))
		{
			LogKeyPress("F10", 14);

			TotalUses = TotalUses + 1;

			printf("[STATS] Total uses: %d\n", TotalUses);

			SetForegroundWindow(Clumsy);

			// Configure this
			SetCursorPos(51, 102);
			MouseClick();

			std::this_thread::sleep_for(std::chrono::milliseconds(400));

			SetForegroundWindow(GameWindow);
		}

		if (GetAsyncKeyState(VK_F11))
		{
			TerminateProcess(GetCurrentProcess(), 0);
		}

		if (GetAsyncKeyState(VK_F12))
		{
			POINT point;

			std::this_thread::sleep_for(std::chrono::milliseconds(250));

			LogKeyPress("F12", 14);

			if (GetCursorPos(&point))
				printf("[LOG] Cursor Pos: %d, %d\n", point.x, point.y);
		}
	}

	return 0;
}