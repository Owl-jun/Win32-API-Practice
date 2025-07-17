#pragma once

#include <iostream>
#include <Windows.h>
#include <assert.h>
#include <cwchar>

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;

#include <string>
using std::string;
using std::wstring;

#include <unordered_map>
using std::unordered_map;

#include <utility>
using std::make_pair;

#include "struct.h"
#include "define.h"
#include "func.h"

#pragma comment(lib, "Msimg32.lib")