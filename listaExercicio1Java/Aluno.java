package listaExercicio1Java;

public class Aluno {
    private String nome;
    private String matricula;
    private float[] notas;
    private int quantNotas = 0;

    public Aluno(String nome, String matricula, int quantNotas) {
        this.nome = nome;
        this.matricula = matricula;
        notas = new float[quantNotas];
    }
    public Aluno(String nome, String matricula) {
        this(nome, matricula, 4);
    }
    public Aluno(String nome) {
        this(nome, "000000000", 4);
    }
    public Aluno(int quantNotas) {
        this("fulano", "000000000", quantNotas);
    }
    public Aluno() {
        this("fulano", "000000000", 4);
    }

    public void adicionaNotas(float nota){
        if(quantNotas < notas.length)
            notas[quantNotas++] = nota;
    }

    public float calcular_media(){
        float soma = 0;
        for(int i = 0; i < quantNotas; i++)
            soma += notas[i];
        return soma / quantNotas;
    }

    public void imprimeAluno() {
        System.out.println("Nome: " + this.nome + " / Matrícula: " + this.matricula);
    }


}
