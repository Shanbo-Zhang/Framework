#pragma once

#include"../General.h"
#include"Application.h"
#include"../Common/Rect.h"

class Window {
private:

	bool enabled_;
	bool focused_;
	bool visible_;
	bool minimized_;
	bool maximized_;
	bool fullScreen_;

	Rect rect_;
	Rect minimumRect_;
	Rect maximumRect_;
};