#pragma once

#ifndef _BLOWFISH_H
#define _BLOWFISH_H

#define ECB 0  //电子密码本
#define CBC 1  //加密块链
#define CFB 2  //加密反馈
#define MAX_KEY_SIZE 56
#define MAX_PBLOCK_SIZE 18     //P盒大小
#define MAX_SBLOCK_XSIZE 4     //S盒横大小
#define MAX_SBLOCK_YSIZE 256   //S盒列大小

#define KEY  ("!BasicAntiCheat!")

/*Block Structure*/
typedef struct {
	unsigned int m_uil; /*Hi*/
	unsigned int m_uir; /*Lo*/
}SBlock;
typedef struct {
	SBlock m_oChain;
	unsigned int m_auiP[MAX_PBLOCK_SIZE];
	unsigned int m_auiS[MAX_SBLOCK_XSIZE][MAX_SBLOCK_YSIZE];
}Blowfish;
/****************************************************************************************/
/*Constructor - Initialize the P and S boxes for a given Key*/
ULONG BlowFishInit(Blowfish* blowfish, unsigned char* ucKey, size_t keysize);
/*Encrypt/Decrypt from Input Buffer to Output Buffer*/
ULONG Encrypt(Blowfish* blowfish, const unsigned char* in, size_t siz_i, unsigned char* out, size_t siz_o, ULONG iMode);
ULONG Decrypt(Blowfish* blowfish, const unsigned char* in, size_t siz_i, unsigned char* out, size_t siz_o, ULONG iMode);
/****************************************************************************************/
VOID HexStr2CharStr(unsigned char* pszHexStr, ULONG iSize, unsigned char* pucCharStr);
VOID CharStr2HexStr(unsigned char* pucCharStr, ULONG iSize, unsigned char* pszHexStr);

VOID TestBlowfish();

VOID DecryptData(PVOID pInAddr, PVOID pOutAddr);

#endif // !_BLOWFISH_H