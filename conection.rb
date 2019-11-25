require_relative 'structs.rb'

#test

#casas predeterminadas
lnodos = []

a = Nodo.new(1,1,1)
b = Nodo.new(2,1,3)
c = Nodo.new(3,1,5)
d = Nodo.new(4,3,1)
e = Nodo.new(5,3,3)
f = Nodo.new(6,3,5)
g = Nodo.new(7,5,1)
h = Nodo.new(8,5,3)
i = Nodo.new(9,5,5)

lnodos.push(a,b,c,d,e,f,g,h,i)

mred = Grid.new(1,2)

for i in 0...lnodos.size() do
    mred.add_nodo(lnodos[i])
end

p dist(1,1,1,2)

mred.pair_up(a)

mred.imprimir_nodos