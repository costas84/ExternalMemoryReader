#include <Windows.h>

int main(int argc, char** argv) {
	HWND wesnoth_window = FindWindow(NULL, L"The Battle for Wesnoth - 1.14.9");

	DWORD process_id = 0;
	GetWindowThreadProcessId(wesnoth_window, &process_id);

	HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	DWORD gold_value = 0;
	DWORD bytes_read = 0;
	ReadProcessMemory(wesnoth_process, (void*)0x017EECB8, &gold_value, 4, &bytes_read);
	return 0;
}