![image](https://github.com/user-attachments/assets/cfb9abfe-d406-4690-87df-3b4572be2f55)<h1>Travel Planner using Djikstras Algorithm in C</h1>
<h2>Introduction</h2>
<div><p>The Travel Planner project is a software tool designed to assist users in planning optimal travel routes within Pune district, Maharashtra, India. Leveraging Dijkstra's Algorithm, the application calculates the shortest path between selected talukas (sub-districts), helping users minimize travel distance and time. The program also provides information on popular tourist attractions and recommended accommodations for each taluka, enhancing the user's travel experience. With features such as an adjacency matrix representing interconnectivity between talukas and an intuitive interface for route selection, this project combines algorithmic efficiency with practical usability. </p>
<p> Here in this project distance between 2 talukas of Pune District is calculated. The Adjacency Matrix represents the distance between 2 talukas. Only the distance between talukas that are Closely connected or directly connected to each other are calculated. According to which 0 represents no direct connection between two talukas.</p>
<p>Total 13 Talukas of Pune district are considered.</p></div>
<h2>Martix Representation</h2>
<div><p>The adjacency matrix in this project represents the distances between the 13 talukas in Pune district. Here's how it is constructed and calculated:</p>
<ul><li>Representation of Talukas:Each taluka is assigned an index, ranging from 0 to 12.
For example, 0 represents Junnar, 1 represents Ambegaon, and so on.</li>
<li>Graph Representation:The talukas and their connections are treated as a graph, where each node represents a taluka, and edges represent direct road connections between them.</li>
<li>Distance Mapping:The distance (in kilometers) between talukas is mapped based on real-world data (such as maps or geographical surveys).
If two talukas are directly connected, their distance is recorded in the matrix. For example, the distance between Junnar and Ambegaon is 34 km, so the matrix entry at [0][1] and [1][0] is 34.
If no direct connection exists, the matrix entry is 0.</li>
<li>Symmetry of the Matrix:The matrix is symmetric since the distance from A to B is the same as B to A.</li>
<li>Zero Values:Diagonal entries are set to 0 because the distance from a taluka to itself is zero.
Non-connected talukas have 0 entries to indicate no direct road.</li>
</ul>
</div>
<img src="[https://www.google.com/url?sa=i&url=https%3A%2F%2Fin.pinterest.com%2Fpin%2F752664156451251817%2F&psig=AOvVaw3BFH0TnhYLevQI5-vV3cX4&ust=1733251381999000&source=images&cd=vfe&opi=89978449&ved=0CBQQjRxqFwoTCMjZ59veiYoDFQAAAAAdAAAAABAE](https://i.pinimg.com/736x/63/46/17/63461720d34dd04c9c41df9e141989bc.jpg)" alt="Pune District Map"> 
