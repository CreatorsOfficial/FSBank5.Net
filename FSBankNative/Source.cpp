#include <stdio.h>
#include <iostream>
#include <FSB/fsbank.h>
#include <string>
#include <cstring>

using namespace std;

extern "C" _declspec(dllexport) void Create();

void Create()
{
	cout << "Enter Path for the FSBank to store cache:-     " << endl;
	string cachePath;
	cin >> cachePath;
	FSBANK_RESULT result = FSBank_Init(FSBANK_FSBVERSION_FSB5, FSBANK_INIT_NORMAL, 2, cachePath.c_str());
	cout << "FSBank Initialized" << endl;
	cout << "FSBank API Result:-  ";
	cout << FSBANK_RESULT_TOSTRING(result) << endl;
	cout << "Enter File Path to wav:-    ";
	string path;
	cin >> path;


	FSBANK_SUBSOUND subsound = { NULL };
	cout << "/n Subsound initialized zero/NULL" << endl;
	int quality = NULL;
	cout << "Enter subsound quality:-    ";
	cin >> quality;
	const char* const msg = path.c_str();
	subsound.fileNames = &msg;
	subsound.overrideFlags = FSBANK_BUILD_DISABLESYNCPOINTS;
	subsound.overrideQuality = quality;
	subsound.desiredSampleRate = 0;
	subsound.numFileNames = 1;
	const FSBANK_SUBSOUND* newSubsound = &subsound;
	cout << "subsound values assigned" << endl;

	cout << "/n Fsb5 format types:-  " << endl;
	cout << "0:- FSBANK_FORMAT_PCM" << endl;
	cout << "1:- FSBANK_FORMAT_PCM_BIGENDIAN" << endl;
	cout << "2:- FSBANK_FORMAT_IMAADPCM" << endl;
	cout << "3:- FSBANK_FORMAT_MP2" << endl;
	cout << "4:- FSBANK_FORMAT_MP3" << endl;
	cout << "5:- FSBANK_FORMAT_XMA" << endl;
	cout << "6:- FSBANK_FORMAT_AT9_PSVITA" << endl;
	cout << "7:- FSBANK_FORMAT_AT9_PS4" << endl;
	cout << "8:- FSBANK_FORMAT_VORBIS" << endl;
	cout << "9:- FSBANK_FORMAT_FADPCM" << endl;
	cout << "10:- FSBANK_FORMAT_MAX" << endl;

	cout << "" << endl;
	int formatEnum = NULL;
	cin >> formatEnum;
	cout << "" << endl;
	cout << "Enter OutputPath for fsb5:-    ";
	string outputPath;
	cin >> outputPath;
	cout << "" << endl;
	string extension = ".fsb5";
	string completepath = outputPath + extension;

	result = FSBank_Build(newSubsound, 1, FSBANK_FORMAT_VORBIS, FSBANK_BUILD_DEFAULT | FSBANK_BUILD_DONTLOOP, quality, NULL, completepath.c_str());
	cout << "building........." << endl;
	cout << "FSBank API Result for build:-     ";
	cout << FSBANK_RESULT_TOSTRING(result) << endl;
	getchar();
}
