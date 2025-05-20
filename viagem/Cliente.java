package viagem;

public class Cliente{
    private String nome, cpf;
    private Dependente[] dependentes;
    private int tamanho = 0;

    public Cliente(String nome, String cpf, int quantDependentes){
        this.nome = nome;
        this.cpf = cpf;
        this.dependentes = new Dependente[quantDependentes];
    }
    public Cliente(String nome, String cpf){
        this(nome, cpf, 30);
    }

    public Cliente(String nome){
        this(nome, "000.000.000-00",30);
    }

    public Cliente(){
        this("irineu","000.000.000-00", 30);
    }
    
    public void adicionaDependente(String nome){
        if(tamanho < dependentes.length) dependentes[tamanho++] = new Dependente(nome, this);
    }

    public String getNomeCliente(){
        return this.nome;
    }

    public String getCpfCliente(){
        return this.cpf;
    }

    public void setNomeCliente(String nome){
        this.nome = nome;
    }

    public void setCpfCliente(String cpf){
        this.cpf = cpf;
    }

    public String getDependente(int tamanho){
        return dependentes[tamanho].getDependente();
    }

}
/*
 * O(n)
 * O(n)
 * o(n)
 * o(n)
 * 
 */