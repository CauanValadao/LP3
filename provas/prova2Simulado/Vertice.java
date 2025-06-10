package prova2Simulado;

public class Vertice {
    private Ponto2D[] vertices;
    private int quantVertices = 0;

    public Vertice(int totalVertices){
        vertices = new Ponto2D[totalVertices];
    }
    public Vertice(Ponto2D ponto){
        vertices = new Ponto2D[4];
        vertices[quantVertices++] = ponto; 
    }
    public Vertice(Vertice outroVertice){
        this.vertices = new Ponto2D[outroVertice.vertices.length];
        for(quantVertices = 0; quantVertices < outroVertice.quantVertices; quantVertices++)
            this.vertices[quantVertices] = new Ponto2D(outroVertice.vertices[quantVertices].getX(), outroVertice.vertices[quantVertices].getY());
    }

    public boolean adicionaVertice(double x, double y){
        if(quantVertices > vertices.length) return false;
        vertices[quantVertices++] = new Ponto2D(x, y);
        return true;
    }

    public boolean adicionaVertice(Ponto2D ponto){
       return adicionaVertice(ponto.getX(), ponto.getY());
    }

    public void mostraPontos(){
        for(int i = 0; i < quantVertices; i++){
            System.out.println(vertices[i]);
        }
    }

}
