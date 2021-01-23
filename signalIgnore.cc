#include <napi.h>
#include <signal.h>

using namespace Napi;

Value IgnoreSignal(const CallbackInfo& info) {
  Env env = info.Env();
  if (info.Length() < 1 || !info[0].IsNumber())
  {
	  TypeError::New(env, "signal number is missing").ThrowAsJavaScriptException();
	  return env.Undefined();
  }
  int signalNumber = info[0].As<Number>().Int32Value();
  signal (signalNumber, SIG_IGN);
  return env.Undefined();
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "ignoreSignal"), Function::New(env, IgnoreSignal));
  return exports;
}

NODE_API_MODULE(setsigignore, Init)