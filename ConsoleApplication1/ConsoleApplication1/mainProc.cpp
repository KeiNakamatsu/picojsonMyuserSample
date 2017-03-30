// ConsoleApplication1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "mainProc.h"
#include "picojson.h"

void mainProc::execute() {

	const char* json = "{\"a\":22,\"secondA\":{\"inA\":1}},{\"b\":22,\"secondA\":{\"inA\":1}}";
	picojson::value v;
	std::string err;
	//json�I�u�W�F�N�g�Ƀp�[�X�o���邩
	const char* json_end = picojson::parse(v, json, json + strlen(json), &err);
	if (!err.empty()) {
		std::cerr << err << std::endl;
	}

	//�I�u�W�F�N�g�̏ꍇ��const_iterator�Ń��[�v
	const picojson::value::object& obj = v.get<picojson::object>();
	for (picojson::value::object::const_iterator i = obj.begin(); i != obj.end(); ++i) {
		std::cout << i->first << ":";
		//�I�u�W�F�N�g�̏ꍇ�͍ċA���[�v
		if (i->second.is<picojson::object>()) {
			i->second.get<picojson::object>();
			const picojson::value::object& inObj = i->second.get<picojson::object>();
			for (picojson::value::object::const_iterator j = inObj.begin(); j != inObj.end(); ++j) {
				std::cout << j->first << ":" << j->second.to_str() << " ";
			}
		} else {
			std::cout << i->second.to_str() << " ";
		}
	}
	std::cout << std::endl;

}


void mainProc::execute_array() {

	const char* json = "[\"a\",\"b\",\"c\",\"d\",\"e\"]";
	picojson::value v;
	std::string err;
	//json�I�u�W�F�N�g�Ƀp�[�X�o���邩
	const char* json_end = picojson::parse(v, json, json + strlen(json), &err);
	if (!err.empty()) {
		std::cerr << err << std::endl;
	}

	//�I�u�W�F�N�g�̏ꍇ��const_iterator�Ń��[�v
	const picojson::value::array& arrayObj = v.get<picojson::array>();
	for (picojson::value::array::const_iterator i = arrayObj.begin(); i != arrayObj.end(); ++i) {
		std::cout << i->serialize() << " ";
	}
	std::cout << std::endl;

}
