def dist (x1, x2, y1, y2) #rrevisaaaaaar
    a = (x2-x1).abs**2
    b = (y2-y1).abs**2
    c = Math.sqrt(a+b)
    return c
end

class Nodo
    attr_accessor :id, :x, :y, :fis_con, :com_con, :consumo
    def initialize (id,x,y)
        @id = id
        @x = x
        @y = y
        @fis_con = Array.new
        @com_con = Array.new
        @consumo = Array.new 
    end

    #crear conecciones
    def add_fis_con (n)
        @fis_con.push(n)
    end

    def add_com_con (n)
        @com_con = com_con.push(n)
    end

    #imprmir
    def imprimir_fis_con
        print(" fis_con: ")
        for i in 0...@fis_con.size() do
            print @fis_con[i].id," "
        end
    end
    
    def imprimir_com_con
        print(" com_con: ")
        for i in 0...@com_con.size() do
            print @com_con[i].id," "
        end
    end
    
end

class Grid
    attr_accessor :fis_radio, :com_radio, :lista_nodos
    def initialize (fis_radio, com_radio)
        @fis_radio = fis_radio
        @com_radio = com_radio
        @lista_nodos = Array.new
    end

    def add_nodo (n)
        @lista_nodos.push(n)
    end

    def pair_up (n) #conectar el nodo con todos los nodos posibles
        print "fr=",@fis_radio, " cr = ",@com_radio,"\n\n"
        for i in 0...@lista_nodos.size() do
            if n.id != @lista_nodos[i].id
=begin DEBUG
                print "n =", n.x," ",n.y,"\n"
                print "nodo = ", @lista_nodos[i].x," ",@lista_nodos[i].y,"\n"
                d = dist(n.x, n.y, @lista_nodos[i].x, @lista_nodos[i].y)
                print "d = ",d," ..."
=end
                if d <= @fis_radio
                    #p "fisc"
                    n.add_fis_con(@lista_nodos[i])
                end

                if d <= @com_radio
                    #p "comc"
                    n.add_com_con(@lista_nodos[i])
                end
                puts;
            end
        end
    end

    #imprimir
    def imprimir_nodos
        for i in 0...@lista_nodos.size() do
            print @lista_nodos[i].id, " (", @lista_nodos[i].x,",",@lista_nodos[i].y,") "
            @lista_nodos[i].imprimir_fis_con; @lista_nodos[i].imprimir_com_con; puts;
        end 
    end

end