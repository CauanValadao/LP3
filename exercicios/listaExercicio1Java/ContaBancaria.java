package listaExercicio1Java;

public class ContaBancaria {
    public String conta;
    public double saldo;

    public ContaBancaria(String conta, double saldo) {
        this.conta = conta;
        this.saldo = saldo;
    }
    public ContaBancaria(String conta) {
        this(conta, 0);
    }
    public ContaBancaria(double saldo) {
        this("Conta Padrão", saldo);
    }
    public ContaBancaria() {
        this("Conta Padrão", 0);
    } 

    public double getSaldo(){
        return saldo;
    }

    public void imprimeSaldo(){
        System.out.println("saldo: "+ this.saldo);
    }

    public void depositar(double deposito){
        if(deposito > 0) saldo += deposito;
    }

    public boolean sacar(double saque){
        if(saque < saldo) return false;
        saldo -= saque;
        return true;
    }

    public boolean transferencia(double valor, ContaBancaria conta){
        if(!this.sacar(valor)) return false;
        conta.depositar(valor);
        return true;
    }
}
