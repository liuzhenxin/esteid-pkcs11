#ifndef __TestCardAdapter_H_
#define __TestCardAdapter_H_

#include "CardManager.h"

class TestCardAdapter : public CardManager {
private:
  CardManager *manager;

public:
  TestCardAdapter(CardManager *m) {
    manager = m;
  }

  bool isInReader(unsigned int idx) {
    return manager->isInReader(idx);
  };

  string readCardID() {
    return manager->readCardID();
  };

  string readDocumentID() {
    return  manager->readDocumentID();
  }

  string readCardName(bool firstNameFirst = false) {
    return  manager->readCardName(firstNameFirst);
  };

  bool isDigiID() {
    return  manager->isDigiID();
  }

  bool isSecureConnection() {
    return manager->isSecureConnection();
  }

  bool getRetryCounts(byte &puk, byte &pinAuth, byte &pinSign) {
    return manager->getRetryCounts(puk, pinAuth, pinSign);
  }

  string getReaderName() {
    return manager->getReaderName();
  }

  ByteVec getAuthCert() {
    return manager->getAuthCert();
  }

  ByteVec getSignCert() {
    return  manager->getSignCert();
  };

  ByteVec RSADecrypt(const ByteVec &cipher, const PinString &pin) {
    return manager->RSADecrypt(cipher, pin);
  };

  unsigned int getTokenCount(bool forceRefresh) {
    return manager->getTokenCount(forceRefresh);
  }

  void validateSignPin(const PinString &pinString, byte &i) {
    manager->validateSignPin(pinString, i);
  }

  void validateAuthPin(const PinString &pinString, byte &i) {
    manager->validateAuthPin(pinString, i);
  }

  unsigned int getKeySize() {
    return manager->getKeySize();
  }

  ByteVec sign(const ByteVec &hash, EstEIDManager::AlgType type, EstEIDManager::KeyType keyId, const PinString &pin) {
    return manager->sign(hash, type, keyId, pin);
  }
};

#endif

