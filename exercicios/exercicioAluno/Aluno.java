package exercicioAluno;

public class Aluno {
    private int numMatricula;
    private static int id = 1, ano = 0;
    private String nome, curso, email;
    
    private void setNumMatricula(int numMatricula){
        if(ano == 0)
            ano = numMatricula/10;
        
        if(numMatricula/10 > ano){
                ano = numMatricula/10;
                id = 1;
        }
        if(numMatricula/10 < ano)
            numMatricula = ano * 10 + numMatricula % 10;
        
            numMatricula *= 10000;
            numMatricula += id++;
            this.numMatricula = numMatricula;
    }
 
    public Aluno(int numMatricula, String nome, String curso, String email){
        //matricula
        setNumMatricula(numMatricula);

        //nome
        this.nome = nome;

        //curso
        this.curso = curso;

        //email
        this.email = email;
    }

    public Aluno(Aluno aluno, String curso, int numMatricula){
        //matricula
        setNumMatricula(numMatricula);

        //nome
        this.nome = aluno.nome;

        //curso
        this.curso = curso;

        //email
        this.email = aluno.email;
    }

    public int getMatricula(){
        return this.numMatricula;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCurso(){
        return this.curso;
    }

    public String getEmail(){
        return this.email;
    }

    public boolean igualA(Aluno outroAluno){
        if(this.numMatricula == outroAluno.numMatricula) return true;
        return false;
    }
}
