#include <array>
#include <vector>

// Evaluate matrix-free operator for a 2D truss
//
// topo - topology of the mesh. Each entry in the vector represents a single
//        element, described by the 2 IDs of the nodes of the element.
// n_nodes - total number of nodes in the mesh
// x, y - arrays containing the coordinates of the nodes - i-th entry contains
//        the coordinates of the i-th node
// lhs - left-hand side vector - this is the vector which is to be multiplied by
//       the stiffness matrix. It has a length of 2 * n_nodes (2 DOFs per node)
// rhs - right-hand side - this is the vector where we want to write the result
//       of the multiplication (same length as lhs)
void solution(std::vector<std::array<unsigned, 2>> const& topo, unsigned n_nodes, double const* x, double const* y, double const* lhs, double* rhs);
