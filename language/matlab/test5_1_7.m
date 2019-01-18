function A=test5_1_7
% the example 5.1.7 from the book MATALB
n=4;
for i=1:n
    for j=1:n+1
        if( i==j)
            A(i,j)=2;
        elseif abs(i-j)==1
            A(i,j)=-1;
            else
                A(i,j)=0;
        end
    end
end

        