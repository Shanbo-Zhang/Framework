#pragma once

#include"../General.h"
#include"../Common/ArrayList.h"
#include"../Common/String.h"
#include"Window.h"

class Application {
private:
	static Application* instance_;
	static String platform_;
	static ArrayList<Window*>* windows_;

	bool running;
	bool exiting;

	int argc_;
	Char** argv_;
public:
	Application(int argc, Char** argv) :argc_(argc), argv_(argv) {
		assert(Application::instance_);
		Application::instance_ = this;
	}

	static Application* const GetInstancePtr()noexcept {
		return Application::instance_;
	}

	bool IsRunning()const noexcept {
		return running;
	}

	bool IsExiting()const noexcept {
		return exiting;
	}
};

Application* Application::instance_;