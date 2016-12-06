#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_tableWigetSize = 500;
    m_size=2;
    setup();
    //ui->tableWidget->setColumnCount( m_size);
    //ui->tableWidget->setRowCount( m_size);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    //connect( ui->pushButton_next, SIGNAL(clicked(bool)), this, SLOT( on_pushButton_next_clicked() ) );
    //connect( ui->pushButton_previous, SIGNAL(clicked(bool)), this, SLOT( on_pushButton_previous_clicked() ) );
    //connect( ui->pushButton_quit, SIGNAL(clicked(bool)), this, SLOT( on_pushButton_quit_clicked() ) );
}
void MainWindow::nextStage()
{
    m_size++;
    setup();
}
void MainWindow::previousStage()
{
    m_size --;
    if ( m_size <= 1 )
        m_size = 2;
    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_next_clicked()
{
    m_size ++;
    setup();
}

void MainWindow::on_pushButton_previous_clicked()
{
    m_size --;
    if ( m_size <= 1 )
        m_size = 2;
    setup();
}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
}
void MainWindow::setup()
{

    ui->tableWidget->setColumnCount( m_size);
    ui->tableWidget->setRowCount( m_size);

    QTime now = QTime::currentTime();
    QColor cellColor = genColor();

    qsrand( now.msec() );
    m_targRow = qrand()%m_size;
    m_targColumn = qrand()%m_size;
    QColor targColor = genColor( 50 );

    for ( int i=0; i<m_size; i++ )
    {
        ui->tableWidget->setRowHeight( i, m_tableWigetSize/m_size );
        for ( int j=0; j<m_size; j++ )
        {
            ui->tableWidget->setColumnWidth( j, m_tableWigetSize/m_size );
            ui->tableWidget->setItem( i, j, new QTableWidgetItem );
            ui->tableWidget->item(i,j)->setFlags( ui->tableWidget->item(i,j)->flags() & ~Qt::ItemIsEditable );
            if( i == m_targRow && j == m_targColumn )
                ui->tableWidget->item( m_targRow, m_targColumn)->setBackground( targColor );
            else
                ui->tableWidget->item(i,j)->setBackground( cellColor );
        }
    }
    ui->tableWidget->clearSelection();
    ui->tableWidget->clearFocus();
}

QColor MainWindow::genColor()
{
    QTime now = QTime::currentTime();
    qsrand( now.msec() );
    return QColor( qrand()%256, qrand()%256, qrand()%256, 255 ); // the last one is transparency.

}

QColor MainWindow::genColor( int delta )
{
    QTime now = QTime::currentTime();
    qsrand( now.msec() );
    return QColor( qrand()%256, qrand()%256, qrand()%256, 255 - delta ); // the last one is transparency.

}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if( row == m_targRow && column == m_targColumn )
    {
        // correct
        on_pushButton_next_clicked();
    }
}
