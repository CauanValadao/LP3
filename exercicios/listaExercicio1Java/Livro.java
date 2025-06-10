package listaExercicio1Java;

public class Livro {
    private String titulo;
    private String autor;
    private int ano;
    private boolean disponivel;

    public Livro(String titulo, String autor, int ano){
        this.titulo = titulo;
        this.autor = autor;
        this.ano = ano;
        this.disponivel = true;
    }

    public Livro(String titulo, String autor){
        this(titulo, autor, 2000);
    }

    public Livro(String titulo, int ano){
        this(titulo, "fulano", ano);
    }

    public Livro(String titulo){
        this(titulo, "fulano", 2000);
    }

    public Livro(){
        this("titulo","fulano", 2000);
    }

    public void emprestar(){
        if(this.disponivel) this.disponivel = false;
    }

    public void devolver(){
        if(!this.disponivel) this.disponivel = true;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }
    
    public int getAno() {
        return ano;
    }

    public boolean estaDisponivel(){
        return this.disponivel;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public String toString(){
        return "titulo: " + this.titulo + " / autor: " + this.autor + " / ano: " + this.ano;
    }
}

