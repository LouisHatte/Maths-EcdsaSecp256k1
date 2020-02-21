import sys
import string

import codecs
from Crypto.Hash import keccak

def isPubKey(pubKey):
    if len(pubKey) != 128:
        print("Invalid length of public key, expected 64 bytes length without '0x' prefix")
        return False
    if all(c in string.hexdigits for c in pubKey) == False:
        print('Invalid public key')
        return False
    return True

def getEthAddr(pubKey):
    pubKeyBytes = codecs.decode(pubKey, 'hex')
    keccakHash = keccak.new(digest_bits=256)
    keccakHash.update(pubKeyBytes)
    keccak_digest = keccakHash.hexdigest()

    ethAddrLen = 40
    ethAddr = '0x' + keccak_digest[-ethAddrLen:]
    return ethAddr

if __name__ == '__main__':

    if len(sys.argv) != 2:
        print(f"Please use: python3 {sys.argv[0]} yourPublicKey")
        exit(1)

    pubKey = sys.argv[1]
    if isPubKey(pubKey) == False:
        exit(1)

    ethAddr = getEthAddr(pubKey)
    print('Your Ethereum address is:')
    print(ethAddr)
