package exercicioAluno;

public class Matricula {

    public static void main(String[] args){

        Aluno[] vet = new Aluno[500];

        for(int i = 0; i < 500; i++){
           // vet[i] = new Aluno(i + 20241);
        }
        for(int i = 0; i < 500; i++){
            System.out.printf("%d\n", vet[i].getMatricula());
        }

    }
    
}
