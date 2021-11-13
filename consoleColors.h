#pragma once
#include <Windows.h>

namespace conColors {
	static inline CONSOLE_SCREEN_BUFFER_INFOEX getScreenBuffer()
	{
		CONSOLE_SCREEN_BUFFER_INFOEX scrBuffer;
		scrBuffer.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfoEx(conHandle, &scrBuffer);

		return scrBuffer;
	}

	static inline void setScreenBuffer(CONSOLE_SCREEN_BUFFER_INFOEX scrBuffer)
	{
		HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferInfoEx(conHandle, &scrBuffer);
		SetConsoleTextAttribute(conHandle, 3);
	}

	static inline void setBackground(int r, int g, int b)
	{
		auto scrBuffer = getScreenBuffer();

		scrBuffer.ColorTable[0] = RGB(r, g, b);

		setScreenBuffer(scrBuffer);
	}

	static inline void setForeground(int r, int g, int b)
	{
		auto scrBuffer = getScreenBuffer();

		scrBuffer.ColorTable[3] = RGB(r, g, b);

		setScreenBuffer(scrBuffer);
	}
};
