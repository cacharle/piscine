/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.rs                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:38:19 by charles           #+#    #+#             */
/*   Updated: 2020/05/21 13:40:00 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

pub fn rush(x: i32, y: i32) {
    if x == 0 || y == 0 {
        return ;
    }

    if x >= 1 {
        print!("A");
    }
    for _ in 1..x - 1 {
        print!("B");
    }
    if x >= 2 {
        print!("A");
    }
    print!("\n");

    for _ in 1..y - 1 {
        print!("B");
        for _ in 1..x - 1 {
            print!(" ");
        }
        if x >= 2 {
            print!("B");
        }
        print!("\n");
    }

    if y > 1 {
        if x >= 1 {
            print!("C");
        }
        for _ in 1..x - 1 {
            print!("B");
        }
        if x >= 2 {
            print!("C");
        }
        print!("\n");
    }
}
