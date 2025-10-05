#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(int num, Cliente t, double s)
    : numero(num), titular(t), saldo(s) {}

void ContaBancaria::depositar(double valor) {
    if (valor > 0) {
        saldo += valor;
        cout << "Depositado R$ " << valor << " na conta " << numero << endl;
    } else {
        cout << "Valor inv�lido para dep�sito." << endl;
    }
}

void ContaBancaria::sacar(double valor) {
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        cout << "Sacado R$ " << valor << " da conta " << numero << endl;
    } else {
        cout << "Saque n�o realizado. Saldo insuficiente ou valor inv�lido." << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        destino.saldo += valor;
        cout << "Transferido: R$ " << valor
             << " da conta " << numero
             << " para a conta " << destino.numero << endl;
    } else {
        cout << "Transfer�ncia n�o realizada. Saldo insuficiente ou valor inv�lido." << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    double metade = valor / 2.0;
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        destino1.saldo += metade;
        destino2.saldo += metade;
        cout << "Transferido: R$ " << metade
             << " para cada conta (" << destino1.numero
             << " e " << destino2.numero
             << ") da conta " << numero << endl;
    } else {
        cout << "Transfer�ncia n�o realizada. Saldo insuficiente ou valor inv�lido." << endl;
    }
}

void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome()
         << ", CPF: " << titular.getCpf() << endl;
    cout << "N�mero da Conta: " << numero
         << ", Saldo: R$ " << saldo << endl;
}
