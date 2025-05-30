package listaExercicio1Java;

public class Pessoa{
    private String nome;
    private int idade;

    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public Pessoa(String nome){
        this(nome, 18);
    }

    public Pessoa(int idade){
        this("fulano", idade);
    }

    public Pessoa(){
        this("fulano", 18);
    }

    public int getIdade(){
        return idade;
    }

    public String getNome(){
        return nome;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }

    public void setNome(String nome){
        this.nome = nome;
    }


}