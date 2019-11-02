// Quad tree quadrants index
// *-------*-------*
// |       |       |
// |2      |3      |
// *-------*-------*
// |       |       |
// |0      |1      |
// *-------*-------*

#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
    Point(int t_x=0, int t_y=0){
        x = t_x, y = t_y;
    }

    string toString(){
        return "("+to_string(x)+","+to_string(y)+")";
    }

    double distanceToMe(int t_x, int t_y){
        return sqrt(pow(x - t_x, 2) + pow(y - t_y, 2));
    }
};

template <typename T> class QuadTree{  
private:
    struct Node{
        T value;
        Point point;
        Node(T t_value, Point t_point){
            value = t_value,point = t_point;
        }
        Node(T t_value, int t_x, int t_y){
            value = t_value;
            point = Point(t_x,t_y);
        }
        string toString(){
            return value+" at: "+point.toString();
        }
    };

    Point top_right;
    Point bottom_left;
    Node *node = nullptr;
    vector<QuadTree*> quadrants = vector<QuadTree*> (4,nullptr);
    bool isLeaf = true;

    bool inBoundaries(Point point){
        return point.x >= bottom_left.x &&
                point.y >= bottom_left.y &&
                point.x <= top_right.x &&
                point.y <= top_right.y;
    }

    void split(){
        int mid_x = bottom_left.x+(top_right.x-bottom_left.x)/2;
        int mid_y = bottom_left.y+(top_right.y-bottom_left.y)/2;

        quadrants[0] = new QuadTree<T>(bottom_left,Point(mid_x,mid_y));
        quadrants[1] = new QuadTree<T>(Point(mid_x,bottom_left.y),Point(top_right.x,mid_y));
        quadrants[2] = new QuadTree<T>(Point(bottom_left.x,mid_y),Point(mid_x,top_right.y));
        quadrants[3] = new QuadTree<T>(Point(mid_x,mid_y),top_right);
        
        isLeaf = false;
    }

    int getIndex(Point point){
        int mid_x = bottom_left.x+(top_right.x-bottom_left.x)/2;
        int mid_y = bottom_left.y+(top_right.y-bottom_left.y)/2;

        if(point.x<mid_x){
            if(point.y<mid_y){
                return 0;
            }else{
                return 2;
            }
        }else{
            if(point.y<mid_y){
                return 1;
            }else{
                return 3;
            }
        }
    }

public:
    QuadTree(Point t_bottom_left, Point t_top_right){
        top_right = t_top_right, bottom_left = t_bottom_left;
    }

    QuadTree(int x_bottom, int y_bottom, int x_top, int y_top){
        bottom_left = Point(x_bottom,y_bottom);
        top_right = Point(x_top,y_top);
    }

    bool insert(T t_value, int t_x, int t_y){
        Node *new_node = new Node(t_value,t_x,t_y);
        if(!inBoundaries(new_node->point)){
            return false;
        }

        if(node == nullptr && isLeaf){
            node = new_node;
            return true;
        }else{
            if(isLeaf){
                split();
            }

            if(node){
                int curr_node_index = getIndex(node->point);
                quadrants[curr_node_index]->insert(node->value,node->point.x, node->point.y);
                node = nullptr;
            }
            
            int new_node_index = getIndex(new_node->point);
            return quadrants[new_node_index]->insert(new_node->value,new_node->point.x,new_node->point.y);
        }
    }

    void printQuadTree(){
        cout<<" Bounds: "<<bottom_left.toString()<<"/"<<top_right.toString();
        if(node) {
            cout<<" value "<<node->toString()<<endl;
        }
        if(!isLeaf) {
            cout<<endl<<"Children: "<<endl;
            for(auto quadrant : quadrants){
                if(quadrant) {
                    quadrant->printQuadTree();
                }
            }
        }
    }

    //TODO make nearest neighboor search algorithm
};

int main(){
    QuadTree<string> quadtree(0,0,20,20);
    quadtree.insert("João",1,1);
    quadtree.insert("Maria",6,8);
    quadtree.printQuadTree();
    return 0;
}