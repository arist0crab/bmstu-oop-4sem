#include "figure.h"

status_t move_point(point_t &point, const move_data_t &move_data);
status_t move_points(points_t &points, const move_data_t move_data);

status_t check_figure_valid(const points_t &points, const vector<edge_t> &edges);
status_t check_index_valid(const int array_size, const int index);

status_t read_points_from_file(figure_t &figure, ifstream &filestream);
status_t read_edges_from_file(figure_t &figure, ifstream &filestream);
status_t free_figure(figure_t &figure);

// ===================================
// Поворот фигуры
// ===================================

// TODO

// ===================================
// Сдвиг фигуры
// ===================================

status_t move_figure(figure_t &figure, const move_data_t &move_data)
{
    status_t sc = check_figure_valid(figure.points, figure.edges);

    if (sc != SUCCESS)
        free_figure(figure);
    else
    {
        move_point(figure.center, move_data);
        move_points(figure.points, move_data);
    }

    return sc;
}

status_t move_points(points_t &points, const move_data_t move_data)
{
    for (size_t i = 0; i < points.size; i++)
        move_point(points.array[i], move_data);

    return SUCCESS;
}

status_t move_point(point_t &point, const move_data_t &move_data)
{
    point.x += move_data.dx;
    point.y += move_data.dy;
    point.z += move_data.dz;

    return SUCCESS;
}

// ===================================
// Отрисовка фигуры
// ===================================

status_t draw_figure(figure_t &figure, draw_scene_t &scene)
{
    status_t sc;
    point_t p1, p2;
    double x1, y1, x2, y2; 

    sc = check_figure_valid(figure.points, figure.edges);
    if (sc == ERR_FIGURE_DATA) 
        free_figure(figure);

    if (sc == SUCCESS)
    {
        scene.scene->clear();
        for (const auto &edge : figure.edges)
        {        
            p1 = figure.points.array[edge.point_1];
            p2 = figure.points.array[edge.point_2];
            x1 = p1.x + scene.width / 2;
            y1 = p1.y + scene.height / 2;
            x2 = p2.x + scene.width / 2;
            y2 = p2.y + scene.height / 2;
            scene.scene->addLine(x1, y1, x2, y2);
        }
    }
    
    return SUCCESS;
}

// ===================================
// Чтение фигуры из файла
// ===================================

status_t read_figure_from_file(figure_t &figure, const string filename)
{
    status_t sc = SUCCESS;

    free_figure(figure);

    ifstream filestream(filename);
    if (!filestream.is_open()) 
        sc = ERR_FILE;

    if (sc == SUCCESS)
    {
        read_points_from_file(figure, filestream);
        read_edges_from_file(figure, filestream);
        filestream.close();
    }

    sc = check_figure_valid(figure.points, figure.edges);
    if (sc == ERR_FIGURE_DATA) 
        free_figure(figure);

    return sc;
}

status_t read_points_from_file(figure_t &figure, ifstream &filestream)
{
    status_t sc;
    point_t point;
    size_t points_quantity;

    filestream >> points_quantity;

    sc = allocate_points_array(figure.points, points_quantity);

    for (size_t i = 0; sc == SUCCESS && i < points_quantity; i++)
    {
        filestream >> point.x >> point.y >> point.z;
        push_back_point(figure.points, point);
    }

    return SUCCESS;
}

status_t read_edges_from_file(figure_t &figure, ifstream &filestream)
{
    size_t edges_quantity;
    edge_t edge;

    filestream >> edges_quantity;
    
    for (size_t i = 0; i < edges_quantity; i++)
    {
        filestream >> edge.point_1 >> edge.point_2;
        figure.edges.push_back(edge);
    }

    return SUCCESS;
}

// ===================================
// Проверка валидности фигуры
// ===================================

status_t check_figure_valid(const points_t &points, const vector<edge_t> &edges)
{
    status_t sc = SUCCESS;

    if (points.size == 0 || edges.empty())    
        sc = ERR_FIGURE_DATA;

    // TODO проверить центр    

    for (size_t i = 0; sc == SUCCESS && i < edges.size(); i++)
    {
        if (check_index_valid(points.size, edges[i].point_1))
            sc = ERR_FIGURE_DATA;
        if (check_index_valid(points.size, edges[i].point_2))
            sc = ERR_FIGURE_DATA;
    }   

    return sc;
}

status_t check_index_valid(const int array_size, const int index)
{
    return (index < 0 || index >= array_size) ? ERR_OUT_OF_RANGE : SUCCESS;;
}

// ===================================
// Освобождение фигуры
// ===================================

status_t free_figure(figure_t &figure)
{
    free_points(figure.points);
    figure.edges.clear();

    return SUCCESS;
}

status_t init_figure(figure_t &figure)
{
    init_point(figure.center);
    init_points(figure.points);
    // TODO

    return SUCCESS;
}