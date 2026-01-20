import itertools
import matplotlib.pyplot as plt
import math
import matploimport streamlit as st
import matplotlib.pyplot as plt
import math
import matplotlib.patches as patches
import pandas as pd
import itertools 

# --- TSP Core Logic ---
def calculate_distance(path, dist_matrix):
    total = 0
    for i in range(len(path) - 1):
        total += dist_matrix[path[i]][path[i+1]]
    return total

def nearest_neighbor(start_city, dist_matrix):
    n = len(dist_matrix)
    visited = [False] * n
    path = [start_city]
    visited[start_city] = True
    current = start_city
    for _ in range(n - 1):
        next_city = None
        min_dist = float('inf')
        for neighbor in range(n):
            if not visited[neighbor] and dist_matrix[current][neighbor] < min_dist:
                min_dist = dist_matrix[current][neighbor]
                next_city = neighbor
        path.append(next_city)
        visited[next_city] = True
        current = next_city
    full_path = path + [start_city]
    return full_path, calculate_distance(full_path, dist_matrix)

def branch_and_bound_all(dist_matrix):
    n = len(dist_matrix)
    all_paths = []
    # Exhaustive search for small n
    for p in itertools.permutations(range(1, n)):
        path = [0] + list(p) + [0]
        all_paths.append((path, calculate_distance(path, dist_matrix)))
    all_paths.sort(key=lambda x: x[1])
    return all_paths

# --- FIXED Plotting function ---
def draw_tsp_on_ax(ax, path, dist_matrix, title, color='red', show_all=False):
    n = len(dist_matrix)
    radius = 3 
    angle_step = 2 * math.pi / n
    coords = {i: (radius * math.cos(i * angle_step), radius * math.sin(i * angle_step)) for i in range(n)}
    
    # 1. Show all background connections AND their weights
    if show_all:
        for i in range(n):
            for j in range(i + 1, n): # i+1 prevents double labels on same line
                x1, y1 = coords[i]; x2, y2 = coords[j]
                ax.plot([x1, x2], [y1, y2], color='lightgray', lw=0.5, ls='--', zorder=1)
                # Display the weight in the middle of the dashed line
                mid_x, mid_y = (x1 + x2) / 2, (y1 + y2) / 2
                ax.text(mid_x, mid_y, str(dist_matrix[i][j]), color='gray', 
                        fontsize=8, ha='center', va='center', 
                        bbox=dict(facecolor='white', alpha=0.6, edgecolor='none'))

    # 2. Draw Cities (Nodes)
    for city, (x, y) in coords.items():
        ax.add_patch(patches.Circle((x, y), 0.45, fc='skyblue', ec='black', zorder=3))
        ax.text(x, y, str(city), ha='center', va='center', fontweight='bold', zorder=4)

    # 3. Draw the active Path (Heuristic or B&B results)
    if path:
        for i in range(len(path) - 1):
            c1, c2 = path[i], path[i+1]
            x1, y1 = coords[c1]; x2, y2 = coords[c2]
            ax.annotate("", xy=(x2, y2), xytext=(x1, y1), 
                        arrowprops=dict(arrowstyle="->", lw=2, color=color, zorder=2))
            ax.text((x1+x2)/2, (y1+y2)/2, str(dist_matrix[c1][c2]), 
                    color='darkgreen', weight='bold', backgroundcolor='white', zorder=5, fontsize=7)
    
    ax.set_title(title, fontsize=10)
    ax.set_xlim(-4, 4); ax.set_ylim(-4, 4); ax.set_aspect('equal'); ax.axis('off')

# --- Streamlit UI ---
st.set_page_config(page_title="TSP Full Analysis", layout="wide")
st.title("🚚 TSP: Detailed Path Analysis")

with st.sidebar:
    st.header("Input Settings")
    n = st.number_input("Number of Cities", min_value=2, max_value=6, value=5)
    st.info(f"Showing {n} variations per method for clarity.")
    matrix_input = []
    for i in range(n):
        row = st.text_input(f"Row {i}", value=" ".join(["0" if j==i else str((i+j)*2) for j in range(n)]))
        matrix_input.append([int(x) for x in row.split()])

if st.button("Generate All Analysis Graphs"):
    dist_matrix = matrix_input

    # --- 1. THE INPUT GRAPH (Now shows weights) ---
    st.subheader("1. Initial Input Connectivity")
    fig_in, ax_in = plt.subplots(figsize=(5, 5))
    draw_tsp_on_ax(ax_in, None, dist_matrix, "Base Distance Matrix Weights", show_all=True)
    st.pyplot(fig_in)

    # --- 2. NEAREST NEIGHBOR ---
    st.divider()
    st.subheader(f"2. Nearest Neighbor Method (Starting from each city)")
    nn_cols = st.columns(n) # Directly uses n
    nn_results = []
    for i in range(n):
        path, cost = nearest_neighbor(i, dist_matrix)
        nn_results.append((path, cost))
        with nn_cols[i]:
            fig, ax = plt.subplots()
            draw_tsp_on_ax(ax, path, dist_matrix, f"Start: {i}\nCost: {cost}", color='orange')
            st.pyplot(fig)

    # --- 3. BRANCH & BOUND (Capped at n) ---
    st.divider()
    st.subheader(f"3. BRANCH & BOUND (Top {n} Paths)")
    bb_solutions = branch_and_bound_all(dist_matrix)
    
    display_n = min(len(bb_solutions), n) # Matches user input n
    bb_cols = st.columns(display_n)
    
    for i in range(display_n):
        path, cost = bb_solutions[i]
        with bb_cols[i]:
            fig, ax = plt.subplots()
            draw_tsp_on_ax(ax, path, dist_matrix, f"Rank {i+1}\nCost: {cost}", color='green')
            st.pyplot(fig)

    # --- 4. FINAL COMPARISON ---
    st.divider()
    st.subheader("4. Final Comparison & Best Outcome")
    best_nn_path, best_nn_cost = min(nn_results, key=lambda x: x[1])
    optimal_path, optimal_cost = bb_solutions[0]

    final_cols = st.columns(2)
    with final_cols[0]:
        fig, ax = plt.subplots()
        draw_tsp_on_ax(ax, best_nn_path, dist_matrix, f"BEST HEURISTIC\nCost: {best_nn_cost}", color='orange')
        st.pyplot(fig)
    with final_cols[1]:
        fig, ax = plt.subplots()
        draw_tsp_on_ax(ax, optimal_path, dist_matrix, f"OPTIMAL (B&B)\nCost: {optimal_cost}", color='red')
        st.pyplot(fig)

    st.success(f"Analysis Complete! Optimal Distance is {optimal_cost}.")
    tlib.patches as patches

# --- Helper Function ---
def calculate_distance(path, dist_matrix):
    total = 0
    for i in range(len(path) - 1):
        total += dist_matrix[path[i]][path[i+1]]
    total += dist_matrix[path[-1]][path[0]]
    return total

# --- Strategy 1: Nearest Neighbor ---
def nearest_neighbor(start_city, dist_matrix):
    n = len(dist_matrix)
    visited = [False] * n
    path = [start_city]
    visited[start_city] = True
    current = start_city

    for _ in range(n - 1):
        next_city = None
        min_dist = float('inf')
        for neighbor in range(n):
            if not visited[neighbor] and dist_matrix[current][neighbor] < min_dist:
                min_dist = dist_matrix[current][neighbor]
                next_city = neighbor
        path.append(next_city)
        visited[next_city] = True
        current = next_city

    return path, calculate_distance(path, dist_matrix)

# --- Strategy 2: Branch and Bound ---
def branch_and_bound_top_5(dist_matrix):
    n = len(dist_matrix)
    best_dist = float('inf')
    all_complete_paths = []

    def solve(current_city, visited, current_path, current_dist):
        nonlocal best_dist

        if current_dist > best_dist and best_dist != float('inf'):
            return

        if len(visited) == n:
            total = current_dist + dist_matrix[current_city][current_path[0]]
            all_complete_paths.append((current_path + [current_path[0]], total))
            if total < best_dist:
                best_dist = total
            return

        for next_city in range(n):
            if next_city not in visited:
                visited.add(next_city)
                solve(
                    next_city,
                    visited,
                    current_path + [next_city],
                    current_dist + dist_matrix[current_city][next_city]
                )
                visited.remove(next_city)

    solve(0, {0}, [0], 0)
    all_complete_paths.sort(key=lambda x: x[1])
    return all_complete_paths[:5]

# --- Advanced Graph Plot Function ---
def plot_tsp_path(path, dist_matrix, title="Optimal TSP Tour"):
    n = len(dist_matrix)

    # Arrange nodes in a circle
    radius = 5
    angle_step = 2 * math.pi / n
    coords = {
        i: (radius * math.cos(i * angle_step),
            radius * math.sin(i * angle_step))
        for i in range(n)
    }

    fig, ax = plt.subplots(figsize=(8, 8))

    # --- Draw Nodes as Circles ---
    for city, (x, y) in coords.items():
        circle = patches.Circle((x, y), 0.6, fc='lightblue', ec='black', zorder=3)
        ax.add_patch(circle)
        ax.text(x, y, str(city), ha='center', va='center',
                fontsize=12, fontweight='bold', zorder=4)

    # --- Draw Edges with Direction & Cost ---
    for i in range(len(path) - 1):
        c1, c2 = path[i], path[i + 1]
        x1, y1 = coords[c1]
        x2, y2 = coords[c2]

        ax.annotate(
            "",
            xy=(x2, y2),
            xytext=(x1, y1),
            arrowprops=dict(arrowstyle="->", lw=2.5, color='red')
        )

        # Edge cost label
        mx, my = (x1 + x2) / 2, (y1 + y2) / 2
        ax.text(mx, my, str(dist_matrix[c1][c2]),
                fontsize=10, color='darkgreen', backgroundcolor='white')

    # Set limits for better view
    margin = 2
    all_x = [x for x, y in coords.values()]
    all_y = [y for x, y in coords.values()]
    ax.set_xlim(min(all_x) - margin, max(all_x) + margin)
    ax.set_ylim(min(all_y) - margin, max(all_y) + margin)

    ax.set_title(title, fontsize=14)
    ax.set_aspect('equal')
    ax.axis('off')
    plt.show()

# --- Main Execution ---
if __name__ == "__main__":
    print("=== TSP PROJECT: Nearest Neighbor vs Branch & Bound ===")

    # Input number of cities and distance matrix
    n = int(input("\nEnter number of cities: "))
    print(f"Enter the distance matrix ({n}x{n}):")
    distances = [list(map(int, input(f"Row {i}: ").split())) for i in range(n)]

    # Nearest Neighbor
    print("\n" + "=" * 50)
    print("STRATEGY 1: NEAREST NEIGHBOR (5 STARTS)")
    print("=" * 50)

    nn_results = []
    for start in range(min(n, 5)):
        path, dist = nearest_neighbor(start, distances)
        nn_results.append(dist)
        path_str = " -> ".join(map(str, path + [path[0]]))
        print(f"Start {start}: {path_str} | Distance: {dist}")

    # Branch and Bound
    print("\n" + "=" * 50)
    print("STRATEGY 2: BRANCH AND BOUND (TOP 5 FOUND)")
    print("=" * 50)

    bb_solutions = branch_and_bound_top_5(distances)
    for i, (path, dist) in enumerate(bb_solutions):
        path_str = " -> ".join(map(str, path))
        print(f"Solution {i+1}: {path_str} | Distance: {dist}")

    # Plot optimal path
    best_path = bb_solutions[0][0]
    plot_tsp_path(best_path, distances, "Optimal TSP Tour (Branch & Bound)")

    # Summary
    best_nn = min(nn_results)
    optimal = bb_solutions[0][1]
    gap = ((best_nn - optimal) / optimal) * 100

    print("\n" + "-" * 50)
    print(f"{'Metric':<25} | {'Value':<15}")
    print("-" * 50)
    print(f"{'Best NN Distance':<25} | {best_nn:<15}")
    print(f"{'Optimal (B&B) Distance':<25} | {optimal:<15}")
    print(f"{'Optimality Gap':<25} | {gap:.2f}%")
    print("-" * 50)
