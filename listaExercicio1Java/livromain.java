package listaExercicio1Java;

public class livromain {
    
    public static void main(String[] args){
        Livro[] livros = new Livro[3];

        livros[0] = new Livro("Harry Potter", "J.K Rowling", 1995);
        livros[1] = new Livro("duna", "herberth", 1950);
        livros[2] = new Livro("fdsaf", "fdfadsf", 3232);

        for(int i = 0; i < 3; i++){
            System.out.printf("titulo: %s / autor: %s / ano: %d\n\n", livros[i].getTitulo(), livros[i].getAutor(), livros[i].getAno());
        }
    }
}
