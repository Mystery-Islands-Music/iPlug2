/* ------------------------------------------------------------
name: "FaustExample"
Code generated with Faust 2.26.2 (https://faust.grame.fr)
Compilation options: -lang cpp -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __Faust1_H__
#define  __Faust1_H__


#include "IPlugFaust.h"

/* BEGIN AUTO GENERATED BY THE FAUST COMPILER ... */
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

class Faust1SIG0 {
	
  private:
	
	int iRec0[2];
	
  public:
	
	int getNumInputsFaust1SIG0() {
		return 0;
	}
	int getNumOutputsFaust1SIG0() {
		return 1;
	}
	int getInputRateFaust1SIG0(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	int getOutputRateFaust1SIG0(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	void instanceInitFaust1SIG0(int sample_rate) {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec0[l0] = 0;
		}
	}
	
	void fillFaust1SIG0(int count, float* table) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec0[0] = (iRec0[1] + 1);
			table[i] = std::sin((9.58738019e-05f * float((iRec0[0] + -1))));
			iRec0[1] = iRec0[0];
		}
	}

};

static Faust1SIG0* newFaust1SIG0() { return (Faust1SIG0*)new Faust1SIG0(); }
static void deleteFaust1SIG0(Faust1SIG0* dsp) { delete dsp; }

static float ftbl0Faust1SIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS Faust1
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class Faust1 : public dsp {
	
 private:
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fVslider1;
	float fRec1[2];
	FAUSTFLOAT fVslider2;
	float fRec2[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("filename", "IPlugFaustDSP.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("name", "FaustExample");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
		Faust1SIG0* sig0 = newFaust1SIG0();
		sig0->instanceInitFaust1SIG0(sample_rate);
		sig0->fillFaust1SIG0(65536, ftbl0Faust1SIG0);
		deleteFaust1SIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = (1.0f / std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate))));
	}
	
	virtual void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(440.0f);
		fVslider2 = FAUSTFLOAT(441.0f);
	}
	
	virtual void instanceClear() {
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual Faust1* clone() {
		return new Faust1();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("FaustExample");
		ui_interface->declare(&fVslider0, "1", "");
		ui_interface->addVerticalSlider("Gain", &fVslider0, 0.0f, 0.0f, 1.0f, 0.100000001f);
		ui_interface->declare(&fVslider1, "2", "");
		ui_interface->addVerticalSlider("Freq1", &fVslider1, 440.0f, 100.0f, 1000.0f, 0.100000001f);
		ui_interface->declare(&fVslider2, "3", "");
		ui_interface->addVerticalSlider("Freq2", &fVslider2, 441.0f, 100.0f, 1000.0f, 0.100000001f);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fVslider0);
		float fSlow1 = (fConst0 * float(fVslider1));
		float fSlow2 = (fConst0 * float(fVslider2));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec1[0] = (fSlow1 + (fRec1[1] - std::floor((fSlow1 + fRec1[1]))));
			output0[i] = FAUSTFLOAT((fSlow0 * ftbl0Faust1SIG0[int((65536.0f * fRec1[0]))]));
			fRec2[0] = (fSlow2 + (fRec2[1] - std::floor((fSlow2 + fRec2[1]))));
			output1[i] = FAUSTFLOAT((fSlow0 * ftbl0Faust1SIG0[int((65536.0f * fRec2[0]))]));
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
		}
	}

};
/* ... END AUTO GENERATED BY THE FAUST COMPILER  */

using namespace iplug;

class Faust_Faust1 : public IPlugFaust
{
public:
  Faust_Faust1(const char* name,
              const char* inputDSPFile = 0,
              int nVoices = 1,
              int rate = 1,
              const char* outputCPPFile = 0,
              const char* drawPath = 0,
              const char* libraryPath = FAUST_SHARE_PATH)
  : IPlugFaust(name, nVoices)
  {
  }

  void Init() override
  {
    mMidiHandler = std::make_unique<iplug2_midi_handler>();
    mMidiUI = std::make_unique<MidiUI>(mMidiHandler.get());
      
    ::dsp* tmpDsp = new FAUSTCLASS();
    
    // Polyphony handling
    bool midiSync = false;
    int nvoices = 0;
    MidiMeta::analyse(tmpDsp, midiSync, nvoices);
    
    if (nvoices > 0)
    {
      dsp_poly* dspPoly = new FAUSTCLASS_POLY(tmpDsp, nvoices, true);
      mMidiHandler->addMidiIn(dspPoly);
      mDSP = std::unique_ptr<::dsp>(dspPoly);
    }
    else
    {
      mDSP = std::unique_ptr<::dsp>(tmpDsp);
    }
    
    // MIDI handling
    mDSP->buildUserInterface(mMidiUI.get());
    mDSP->buildUserInterface(this);
    
    BuildParameterMap();
    
    mInitialized = true;
  }
};

#undef FAUSTCLASS


#endif
