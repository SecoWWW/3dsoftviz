#include "Layout/LayoutThread.h"

#include "Layout/FRAlgorithm.h"
#include "Util/ApplicationConfig.h"

using namespace Layout;

LayoutThread::LayoutThread(Layout::FRAlgorithm* alg)
{
	this->alg = alg;
	appConf = Util::ApplicationConfig::get();
}

LayoutThread::~LayoutThread(void)
{
}

void LayoutThread::run()
{
	this->sleep(appConf->getValue("Layout.Thread.StartSleepTime").toLong());
	alg->Run();
}
void LayoutThread::pause()
{
	alg->PauseAlg();
}
void LayoutThread::play()
{
	alg->RunAlg();
}
void LayoutThread::wakeUp()
{
	alg->WakeUpAlg();
}
void LayoutThread::setAlphaValue(float val)
{
	alg->SetAlphaValue(val);
}
bool LayoutThread::isRunning()
{
	return alg->IsRunning();
}
void LayoutThread::requestEnd()
{
	alg->RequestEnd();
}
void LayoutThread::playEdgeBundling()
{
	alg->RunAlgEdgeBundling();
}
void LayoutThread::stopEdgeBundling()
{
	alg->StopAlgEdgeBundling();
}
void LayoutThread::pauseAllAlg()
{
	//order is important
	alg->StopAlgEdgeBundling();
	alg->PauseAlg();
}
