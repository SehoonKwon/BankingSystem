/**
*@file BankingCommenDecl.h
*전역에 쓸 enum 및 사용자정의 정리
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

#define endl "\n"

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHRAW, INQUIRE, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌 종류
enum { NORMAL = 1, CREDIT = 2 };
