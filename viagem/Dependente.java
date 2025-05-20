package viagem;

public class Dependente {
    private String nome;
    private Cliente cliente;

    public Dependente(String nome, Cliente cliente){
        this.nome = nome;
        this.cliente = cliente;
    }

    public String getDependente(){
        return nome;
    }

    public void setDependente(String nome){
        this.nome = nome;
    }

    public Cliente getCliente(){
        return cliente;
    }


}