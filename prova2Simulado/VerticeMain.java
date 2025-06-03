package prova2Simulado;

public class VerticeMain {
    
    public static void main(String[] args){
        Vertice retangulo = new Vertice(4);

        retangulo.adicionaVertice(0.0,0.0);
        retangulo.adicionaVertice(4,0);
        retangulo.adicionaVertice(0,8);
        retangulo.adicionaVertice(4,8);

        Vertice triangulo = new Vertice(3);

        triangulo.adicionaVertice(0,0);
        triangulo.adicionaVertice(4,0);
        triangulo.adicionaVertice(2,4);

        retangulo.mostraPontos();
        System.out.println("-----");
        triangulo.mostraPontos();

        /*Não é possível representar um cubo, uma vez que a classe Vertice possui apenas 2 atributos representando
        dimensões, portanto seria necessario um terceiro atributo representando a terceira dimensão*/
    }
}
