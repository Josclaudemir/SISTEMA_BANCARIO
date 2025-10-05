#include <iostream>
#include "Cliente.h"
#include "ContaBancaria.h"
using namespace std;

int main() {
    string nome, cpf;
    int numero;
    double saldo;

    //Realiza o cadastro de cada cliente

    cout << "=== Cadastro de Cliente 1 ===" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Numero da conta: ";
    cin >> numero;
    cout << "Saldo inicial: ";
    cin >> saldo;
    cin.ignore(); // limpa buffer
    Cliente cliente1(nome, cpf);
    ContaBancaria conta1(numero, cliente1, saldo);

    cout << "\n=== Cadastro de Cliente 2 ===" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Numero da conta: ";
    cin >> numero;
    cout << "Saldo inicial: ";
    cin >> saldo;
    cin.ignore();
    Cliente cliente2(nome, cpf);
    ContaBancaria conta2(numero, cliente2, saldo);

    cout << "\n=== Cadastro de Cliente 3 ===" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Numero da conta: ";
    cin >> numero;
    cout << "Saldo inicial: ";
    cin >> saldo;
    cin.ignore();
    Cliente cliente3(nome, cpf);
    ContaBancaria conta3(numero, cliente3, saldo);

    // Menu de operações
    int opcao;
    do {
        cout << "\n=== MENU BANCARIO ===" << endl;
        cout << "1. Depositar em conta 1" << endl;
        cout << "2. Sacar da conta 1" << endl;
        cout << "3. Transferir de conta 1 para conta 2" << endl;
        cout << "4. Transferir de conta 1 para conta 2 e conta 3" << endl;
        cout << "5. Exibir saldos" << endl;
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        double valor;
        switch (opcao) {
            case 1:
                cout << "Valor do deposito: ";
                cin >> valor;
                conta1.depositar(valor);
                break;
            case 2:
                cout << "Valor do saque: ";
                cin >> valor;
                conta1.sacar(valor);
                break;
            case 3:
                cout << "Valor da transferencia: ";
                cin >> valor;
                conta1.transferir(valor, conta2);
                break;
            case 4:
                cout << "Valor da transferencia: ";
                cin >> valor;
                conta1.transferir(valor, conta2, conta3);
                break;
            case 5:
                cout << endl;
                conta1.exibirInformacoes();
                conta2.exibirInformacoes();
                conta3.exibirInformacoes();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
