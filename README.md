# Maths - ECDSA Secp256k1

## Description

Ethereum does not explicitly display the public key of a user account.

**Maths ECDSA secp256k1** allows from a private key of Ethereum to get its public key and its address.

For the curious, the Elliptic Curve Digital Signature Algorithm (ECDSA) with as standard of parameters the secp256k1, which allows from a private key to obtain a unique public key, is recoded from scratch.

In this project you can :
- Recover an Ethereum public key from its private key (homemade algorithm in C)
- Recover an Ethereum address from its public key (keccak python library)

## Installation

### I. Prerequisites

You need to install **keccak** python library if you want to get your Ethereum address:
```sh
pip install pycryptodome
```

### II. Project set up

You just need to go to the the project directory and compile it:
```sh
cd Maths-EcdsaSecp256k1/
make
```

### III. Run the project

To **get your public key** you can run from the root directory:
```sh
./bin/pubKey {privateKey}
```

To **get your Ethereum address** you can run from the root directory:
```sh
python3 ethAddr.py {publicKey}
```

## TODO
1. Add logo
2. boyscoot
