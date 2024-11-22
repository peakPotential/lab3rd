For the given Dataset (TFL Bus Safety):
1. Create a bar chart on boroughs field to visualize the trend in the count.
2. Create a line chart for date of incidence for each quarter in a year,
comment on possibilities and suitability of different charts for this
timeline.
3. Create a line chart for date of incidence for each month in a year apply
formatting to display the first letter of the month on X-axis.
4. Create tree maps of all the data fields except date & year and comment
on significance of tree map.
5. Build an interactive dashboard for the above data.
Steps:
1)
 Drag the ‘Borough’ field to the columns shelf.
 Drag ‘Measure Values’ or ‘Count’ to the rows.
 Select ‘Bar Chart’ under ‘Show me’ section.
 Sort the Bar Chart in descending order with Sort By as ‘Field’.
 Rename the worksheet as ‘Bar Chart’.
11
2)
 Drag and drop the ‘Date of incident’ field to the column.
 Drag the ‘Date of incident’ field to the column field it automatically
selects quarter.
 Drag and drop ‘Sheet1(Count)’ field to the rows.
 Rename the worksheet as ‘Line Chart – 1’.
3)
 Create a line chart by following the previous sub-question.
 Right click on ‘Date of incident’ field in column & select ‘Month’.
 Now, right click on any one label in X-axis, then go to format.
 Under header, go to default, then select dates.
 Select first letter under dates.
 Rename the worksheet as ‘Line Chart – 2’.
12
4)
 Drag & drop all fields one by one except ‘Date’ & ‘Year’ to marks
section.
 Click on ‘Show Me’ and select the tree maps chart.
 Rename the Worksheet as ‘Tree Map’.
13
5)
 Click on ‘New Dashboard’ button in the bottom left corner of the
Tableau window.
 Select floating windows under Objects, in Dashboard.
 Drag all the worksheets and drop them in the dashboard.
 Rearrange all the worksheets, once all the worksheets are added.
14



Program – 7
Analysis of revenue in Sales dataset:
1. Create a choropleth map (fill the map) to spot the special trends to show
the state which has the highest revenue.
2. Create a line chart to show the revenue based on the month of the year
(Continuous data based on date).
3. Create a donut chart view to show the percentage of revenue per region by
creating zero axis in the calculated field.
4. Create a butterfly chart by reversing the bar chart to compare female &
male revenue based on product category (Calculated fields based on total).
5. Build an interactive dashboard for the above data.
Steps:
1)
 Double click on ‘State’ field under data.
 Under Map tab click, edit locations and select ‘United States’.
 Drag and drop ‘Total’ to label and color under marks section.
 Select ‘Sum(total)’, right click, format, then under pane, go to default,
under numbers, go to currency(custom), decimal place to 1, display units
in Millions.
 Rename the worksheet as ‘Map’.
15
2)
 Drag and drop ‘Total’ to rows.
 Convert month from string to date, by right click, then change data type
and drag to column.
 Drag and drop ‘Total’ to label under marks section.
 Under marks, select sum(total), right click, format, then under pane, go to
default, under numbers, go to currency(custom), decimal place to 1, display
units in Millions.
 Right Click on Month in columns and select Month i.e. continuous.
 Rename the worksheet as ‘Line Chart’.
3)
 Drag and drop ‘Region’ to column and ‘Total’ to rows.
 Make a pie chart, selecting under ‘Show Me’.
 Drag and drop ‘Region’ & ‘Total’ to label under marks section.
 In label, sum(total) right click, quick table calculation, percent of total.
 Create calculated field, rename to ‘Zero Axis’, write code as 0, then ok.
 Drag and drop ‘Zero Axis’ twice to rows.
16
 Then under marks, two fields of Zero Axis will be present, go to second,
remove all fields, change the color to white then increase the size in 1st,
decrease in 2nd Zero Axis.
 Right click on second Zero Axis in rows, then click dual axis and select
Entire View in Fit tab.
 Rename the worksheet as ‘Donut Chart’.
4)
 Drag and drop ‘Category’ to rows shelf.
 Create 2 calculated fields ‘Female’ and ‘Male’.
 For female revenue, Code is – if [Gender] = ‘F’ then [Total]end - Create
same for male revenue by changing ‘F’ to ‘M’.
 Drag and drop ‘Female’ and ‘Male’ to columns shelf.
 Drag and drop ‘Zero axis’ between female and male revenue in columns.
 Select Zero Axis under Marks Section, Select Text in place of automatic
and Drag Category to text.
 Edit the Female Axis and select reversed.
 Sort the Category and select entire view in fit tab, then disable show header
in Y axis.
 Rename the ‘Zero Axis’ as ‘Category’ by editing, and remove 0 (tick tab).
 Rename the worksheet as ‘Butterfly Chart’.
17
5)
 Click on ‘New Dashboard’ button in the bottom left corner of the
Tableau window.
 Select floating windows under Objects, in Dashboard.
 Drag all the worksheets and drop them in the dashboard.
 Rearrange all the worksheets, once all the worksheets are added.
18




Program – 8
Analysis of sample superstore
1. Create a bar chart to visualize the sales of product of each category by year
with respect to region and also show the profit (Text).
2. Create a bar chart to visualize the sales of product all categories of years
2022 and 2023.
3. Create a horizontal bar chart to visualize the profit by category.
4. Create a map to visualize the profit by state.
5. Build an interactive dashboard for the above data.
Steps:
1)
 Drag and drop ‘Order Date’ and ‘Category’ to columns.
 Drag and drop ‘Sales’ to rows.
 Drag and drop ‘Profit’ to color and label in marks section.
 Under marks, select sum(profit) of label, right click, format, then under
pane, go to default, under numbers, go to currency(custom), decimal place
to 1, display units in Thousands(K).
 Drag & drop ‘Region’ to rows before sales and select entire view in fit tab.
 Rename the worksheet as ‘Bar Chart – 1’.
19
2)
 Drag ‘Order Date’ and ‘Category’ and ‘Sub-Category’ to columns.
 Drag and drop ‘Sales’ to rows.
 Right click on Year (Order Date) in columns, select filter and select only
2022 and 2023.
 Drag and drop ‘Profit’ to color and label in marks section.
 Under marks, select sum(profit) of label, right click, format, then under
pane, go to default, under numbers, go to currency(custom), decimal place
to 1, display units in Thousands (K).
 Rename the worksheet as ‘Bar Chart – 2’.
3)
 Drag and drop ‘Category’ field to rows and add ‘Sub-Category’ also.
 Drag and drop ‘Profit’ to text under marks section.
 Select Horizontal bars under show me.
 Drag and drop ‘Profit’ to colour under marks section.
 Rename the worksheet as ‘Horizontal Bars’.
20
4)
 Drag and drop the ‘State/Province’ field to Details under marks section.
 Under Map tab click, edit locations and select ‘United States’.
 Drag and drop ‘Profit’ to size and label under marks section.
 Select ‘Sum (Profit)’, right click, format, then under pane, go to default, under
numbers, go to currency(custom), decimal place to 1, display units in
Thousands (K).
 Rename the worksheet as ‘Map’.
21
5)
 Click on ‘New Dashboard’ button in the bottom left corner of the
Tableau window.
 Select floating windows under Objects, in Dashboard.
 Drag all the worksheets and drop them in the dashboard.
 Rearrange all the worksheets, once all the worksheets are added. 
