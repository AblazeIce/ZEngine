#pragma once

#ifdef Z_PLATFORM_WINDOWS

int main(int argc,char** argv) 
{
	Z::Log::Init();
	Z_CORE_TRACE("1111");
	//Z_CORE_INFO("1111");
	//Z_CORE_WARN("1111");
	//Z_CORE_ERROR("���ѽ��������");
	////Z_CORE_FATAL("jjjj");
	//Z_INFO("�ҵĹ�������");
	auto app = Z::CreateApplication();
	app->Run();
	delete app;
}
#endif // Z_PLATFORM_WINDOWS

